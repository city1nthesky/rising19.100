#include "defenengine.h"
#include "defenplugins.h"
#include "defenmodproxy.h"
#include "json/json.h"
#include "baseconfig.h"
#include "commonapi.h"
#include "appconfig.h"
#include "communicatebundle.h"
#include "storagebridge.h"
#include "service.h"
#include "Entry/commonentry.h"
#include "Entry/whitelistentry.h"
#include "datacontainer.h"
#include "service.h"
extern "C" {
    #include "crypt/crc32.h"
}

#define SECURITY_FREE(x) if(x) {delete x; x=NULL;}
#define SECURITY_CLOSE(x) if(x) {fclose(x); x=NULL;}
#define SECURITY_CHECK(x, y, z) if(x != y) return z;
#define ASSERT_ZERO(x, y) if(!x) return y;

DefenEngine* DefenEngine::NEW(ServiceBinder *binder, StorageBridge *storage, AppConfig *config) {
    DefenEngine *self = new DefenEngine(binder, storage, config);
    if (self) {
        if (self->Construct()) {
            delete self;
            self = NULL;
        }
    }
    return self;
}

DefenEngine::DefenEngine(ServiceBinder *binder, StorageBridge *storage, AppConfig *config)
                        : KernelApplication (binder, storage, config) {
    mDefenProxy = NULL;
    mFileJudge = NULL;
}

DefenEngine::~DefenEngine() {
    SECURITY_FREE(mDefenProxy);
    SECURITY_FREE(mFileJudge);
}

int DefenEngine::Construct() {
    KernelApplication::Construct();

    mDataContainer = new DefenDataContainer;
    mFileJudge = DefenPlugins::NEW(mDataContainer);

    LoadFileMonitorSetting();

    return 0;
}


list<string> &DefenEngine::GetFolderMonitorList()
{
    return mDataContainer->mFolderMonitorList;
}


int DefenEngine::LoadFileMonitorSetting() {
    mStorage->GetAntiVirusConfig(*mDataContainer->mFileMonitorSetting, AntiVirusSetting::FILE_MONITOR);
    mFileJudge->LoadConfig(mBinder->GetClientUID());

    std::list<WhiteListEntry> datas;
    if (mStorage->GetProcessBlackList(datas) > 0) {
        std::list<WhiteListEntry>::iterator iter;
        for (iter=datas.begin();iter!=datas.end();++iter) {
            mDataContainer->mProcMonitorList.push_back(iter->mPath);
        }
    }

    datas.clear();
    if (mStorage->GetFolderMonitorList(datas) > 0) {
        std::list<WhiteListEntry>::iterator iter;
        for (iter=datas.begin();iter!=datas.end();++iter) {
            mDataContainer->mFolderMonitorList.push_back( string(iter->mPath+string("/*")) );
        }
    }


    list<string> fl = GetFolderMonitorList();
    for(list<string>::iterator it = fl.begin(); it != fl.end(); it++)
    {
        LOG_ZDFY("LoadFileMonitorSetting folder Monitor List: %s", it->c_str());
    }

    mScanCache.clear();
    return 0;
}

int DefenEngine::onDefenEvent(DEFEN_TYPE event, const char *file, void *data) {
    if (NULL == mFileJudge) {
        return 0;
    }

    if (event == DEFEN_PROC_START) {
        // filter the scaned process in cache
        unsigned int hash = rs_crc32((unsigned char*)file, strlen(file));
        map<unsigned int, bool>::iterator iter;
        if (mScanCache.find(hash) != mScanCache.end()) {
            return 0;
        }
    }

    string out;
    //LOG_ZDFY("file %s is changed, will be matched", file);
    DefenPlugins::JudgeResult resp = mFileJudge->Judge(event, string(file), data, out);
    switch (resp) {
    case DefenPlugins::DEFEN_PROC_DENY: {
        return 1;
    }
    case DefenPlugins::DEFEN_FILE_SCAN:
    case DefenPlugins::DEFEN_PROC_EXTENS: {
        LOG_ZDFY("get %s changed, will be scan by GJCZ and type is %d", file, resp);
        // match the rule
        CommandBundle command;
        command.mCommandID = CommandBundle::REMOTE_COMMAND;
        if (resp == DefenPlugins::DEFEN_FILE_SCAN) {
            command.mIntegerValue = CommandBundle::DEFEN_FILE_CHANGED;
            command.mStringValue = GetScanParams(file);
        }
        else if (resp == DefenPlugins::DEFEN_PROC_EXTENS) {
            command.mIntegerValue = CommandBundle::DEFEN_PROC_STARTED;
            command.mStringValue = GetScanParams(out);
        }


        int err = mBinder->NotifyData(FOLDER_RJJH_ZDFY, RJJH_NOTIFY_SOCKET, command);
        if (err>0 && resp == DefenPlugins::DEFEN_PROC_EXTENS) {
            // proc started, detect the virus            
            return 1;
        }
        else if (err == 0 && event == DEFEN_PROC_START) {
            unsigned int hash = rs_crc32((unsigned char*)file, strlen(file));
            mScanCache.insert(make_pair(hash, true));
        }
        LOG_ZDFY("defen scan ret value %d", err);
        break;
    }
    default:{
        break;
    }
    }

    return 0;
}

inline string DefenEngine::GetScanParams(const string& file) {
    // file need scan
    Json::Value json;
    json["file"] = Json::Value(file);

    Json::FastWriter writer;
    return writer.write(json);
}

int DefenEngine::StartFileMonitor() {
    printf("StartFileMonitor1\n");

    if (!mDefenProxy) {
        mDefenProxy = new DefenModProxy;
        mDefenProxy->SetObserver(this);
    }

    //printf("StartFileMonitor2\n");

    if (mDefenProxy && mDefenProxy->Status()==0) {
        //printf("StartFileMonitor3\n");
        list<string> fl = GetFolderMonitorList();
        for(list<string>::iterator it = fl.begin(); it != fl.end(); it++)
        {
            LOG_ZDFY("folder Monitor List: %s", it->c_str());
        }

        LOG_ZDFY("StartFileMonitor");
        return mDefenProxy->Start()?-1:1;
    }
    else {
        return LoadFileMonitorSetting();
    }

    printf("StartFileMonitor4\n");
}

int DefenEngine::StopFileMonitor() {
    LOG_ZDFY("StopFileMonitor");

    if (mDefenProxy) {
        mDefenProxy->Stop();
    }
    return 0;
}

