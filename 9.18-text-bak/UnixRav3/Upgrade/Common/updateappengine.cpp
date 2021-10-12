#include "updateappengine.h"
#include "zip/unixzip.h"
#include "commonapi.h"
#include "updateconfig.h"
#include "baseconfig.h"
#include "updateobserver.h"
#include "updateconfig.h"
#include "net/httprequest.h"
#include "libxml/parser.h"

#include <fstream>
#include <vector>
#include <string>
#include <sys/utsname.h>
#include <unistd.h>
#include <sys/stat.h>

using namespace std;

#define APP_UPDATE_NAVIGATE_FILE    "RSNetVerForUnix.xml"
#define APP_UPDATE_NAVIGATE_URL     "/ruc/esm/linux/RSNetVerForUnix.xml"


/** define in libravcommon.so */
extern "C" int decompress_7z(const char *zip, const char *outfolder);

UpdateAppEngine* UpdateAppEngine::NEW(const std::string &installdir, const std::string& configpath, int center_type) {
    UpdateAppEngine *self = new UpdateAppEngine;
    if (self) {
        if (self->Contruct(installdir, configpath)) {
            delete self;
            self = NULL;
        }
        self->mCenterType = center_type;
    }
    return self;
}

void UpdateAppEngine::SetUpdateMethod(const string& subguid) {
    if (subguid == COMMON_MACHINE_ID || subguid == CHINA_MECHINE_ID) {
        mUpdateMethod = UPDATE_NORMAL_VERSION;
    }
    else {
        mUpdateMethod = UPDATE_ORIGIN_VERSION;
    }
}

int UpdateAppEngine::UnzipFile(const std::string& in, std::string& out) {
#if 0
    UnZip *unzip = new UnZip;

    char strTempPath[512];
    char strTempFile[512];
    int  nResult;

    char *temp = (char*)in.c_str();
    char *szTmpBuf = strrchr(temp, '/');
    if(!szTmpBuf) {
        return -1;
    }

    nResult = szTmpBuf - temp;
    strncpy(strTempPath, temp, nResult);
    strTempPath[nResult] = '\0';
    strcat(strTempPath,"/");

    nResult = unzip->FindFirst(temp, strTempPath, strTempFile);
    if(nResult==0) {
        delete unzip;
        return -1;
    }

    out = strTempPath;

    delete unzip;
    unlink(in.c_str());
#endif
    char *temp = (char*)in.c_str();
    char *szTmpBuf = strrchr(temp, '.');
    if(!szTmpBuf) {
        return -1;
    }

    char strTempPath[512];

    int nResult = szTmpBuf - temp;
    strncpy(strTempPath, temp, nResult);
    strTempPath[nResult] = '\0';

    CUNIXZIP unzip;
    if (0 == unzip.gz_init(in.c_str(), strTempPath, true, 1)) {
        if (0 == unzip.gz_uncompress()) {
            out = strTempPath;
            return 0;
        }
    }

    return -1;
}

int UpdateAppEngine::GetUpdateFileMd5(const std::string& md5file, std::map<std::string, std::string>& out) {
    std::string line;
    std::ifstream stream(md5file.c_str());
    if (!stream) {
        return -1;
    }

    while(std::getline(stream, line)) {
        std::string::size_type begin = line.find_first_of("=");
        if (begin == std::string::npos) {
            break;
        }

        std::string filename = line.substr(0, begin);
        ++begin;
        std::string hash = line.substr(begin, line.length()-begin);

        out[filename] = hash;
    }
    return 0;
}

std::string UpdateAppEngine::GetNewVersion(const std::string& verlistfile) {
    FILE *file;
    if ((file = fopen(verlistfile.c_str(), "rb")) == NULL) {
        return "";
    }

    UPLISTVERSION   veritem;
    memset(&veritem, 0, sizeof(UPLISTVERSION));

    if (1 == fread(&veritem, sizeof(UPLISTVERSION), 1, file)) {

    }
    fclose(file);
    if (veritem.filenum > 1000) {
        return "";
    }
    return veritem.version;
}

int UpdateAppEngine::ParseVersionList(const std::string& verlistfile,
                                   std::map<std::string, std::string>& filemd5,
                                   std::vector<UPDATALISTINFO>& strUpList,
                                   std::vector<std::string>& updateless) {
    FILE *fpList;
    if ((fpList = fopen(verlistfile.c_str(), "rb")) == NULL) {
        return -1;
    }

    int nTot=0;

    UPLISTVERSION   veritem;
    memset(&veritem, 0, sizeof(UPLISTVERSION));

    while (fread(&veritem, sizeof(UPLISTVERSION), 1, fpList) == 1) {
        UPFILEVERSION * pFileVersion = new UPFILEVERSION[veritem.filenum];

        if (fread(pFileVersion, veritem.filenum*sizeof(UPFILEVERSION), 1, fpList) != 1) {
            fclose(fpList);
            delete [] pFileVersion;
            return -1;
        }

        for(int i=0; i<veritem.filenum; i++) {
            UPDATALISTINFO fileinfo;

            fileinfo.filelist = pFileVersion[i];
            fileinfo.filetype = veritem.vername;

            std::string filename = Utils::Path::JoinPath(mInstallDir.c_str(), fileinfo.filelist.filename, NULL);
            if(Utils::Path::FileAvailed(filename)) {
                std::map<std::string, std::string>::iterator iter = filemd5.find(fileinfo.filelist.filename);
                if(iter != filemd5.end()) {
                    std::string hash = Utils::Hash::GetFileMD5(filename);

                    LOG_GLTX("update %s hash is %s\n", fileinfo.filelist.filename, iter->second.c_str());
                    LOG_GLTX("file %s hash is %s\n", filename.c_str(), hash.c_str());

                    if (hash != iter->second) {
                        nTot++;
                        strUpList.push_back(fileinfo);
                    }
                    else {
                        //
                        updateless.push_back(fileinfo.filelist.filename);
                    }
                }
            }
        }

        delete [] pFileVersion;

    }

    fclose(fpList);
    return nTot;
}

int UpdateAppEngine::EmulateEnv(std::vector<UPDATALISTINFO>& strUpList,
                         std::vector<std::string>& unpdateless) {
    return 0;
}

int UpdateAppEngine::BackupOrigin(const std::string &origin) {
    return 0;
}

int UpdateAppEngine::ReplaceFile(const std::string &filepath, const std::string &file) {
    return 0;
}

int UpdateAppEngine::UpdateEntry() {
    string newversion, folder;
    int err = AppUpdate(newversion, folder);
    LOG_GLTX("update error is %d\n", err);

    if (err == 0) {
        if (0 == UpdateFiles(folder, newversion)) {
            if (mObserver) {
                mObserver->OnUpdateEvent(UpdateObserver::UPDATE_EVENT_APP,
                                         UpdateObserver::UPDATE_DOWNLOAD_SUCCESS,
                                         &mCurrentVersion);
            }
        }
        else {
            LOG_GLTX(("bakup and replace file error!"));
        }
    }
    else if (err < 0) {
        if (mObserver) {
            mObserver->OnUpdateEvent(UpdateObserver::UPDATE_EVENT_APP,
                                     UpdateObserver::UPDATE_ERROR,
                                     &err);
        }
    }
    else if (err > 0) {
        if (mObserver) {
            mObserver->OnUpdateEvent(UpdateObserver::UPDATE_EVENT_APP,
                                     UpdateObserver::UPDATE_NEWEST,
                                     &mCurrentVersion);
        }
    }

    return 0;
}

string UpdateAppEngine::GetOfficalAddress(const string &url, const string& serial) {
    const char *RISING_OFFICAL_NAVIGATE_XML = "rsunixver.xml";
    string addr = Utils::Path::JoinPath(url.c_str(), RISING_OFFICAL_NAVIGATE_XML, NULL);

    string header, body, conn;
    int err = http_get(addr, "", header, body, conn);
    if (err) {
        LOG_GLTX("get the offical navigate error");
        return "";
    }

    NavigateModel model;
    if (ParseNavigate(body, model)) {
        return "";
    }

    // 这个值来自网络版, 具体原因不明, 复用
    const int UNIX_NET_PRODUCT_ID = 0x20700100;

    srand((unsigned int )time(NULL));
    string param = string("id=&sn=") + serial + "&time_setup=0&time_overtime=0&type=" + Utils::String::itoa(UNIX_NET_PRODUCT_ID) + "&validate=" + Utils::String::itoa(rand()) + "&ver=3.0";
    string encrypt = Utils::Hash::RSEntrypt(param);

    string source_url = model.mValidate + "?info=" + encrypt + "&version=" + mCurrentVersion;
    string redirect_url;
    http_redirect(source_url, redirect_url);

    if (!redirect_url.empty()) {
        size_t pos = redirect_url.find('?');
        if (string::npos != pos) {
            return redirect_url.substr(0, pos-1);
        }
    }

    return "";
}


int UpdateAppEngine::AppUpdate(string& newversion, string& folder) {
    folder = MakeTmpFolder(UPDATE_TEMP_FOLDER);

    string navigate_url, navigate_file;

    string offline_folder = Utils::Path::JoinPath(mInstallDir.c_str(), mOwnerPath.c_str(), "offline", NULL);
    Utils::Path::CheckPath(offline_folder);

    if (!Utils::Path::PathExists(offline_folder)) {
        LOG_GJCZ("update virus lib can not make folder");
        return -1;
    }

    string final_url = mUpdateConfig.mCenterAddr.second;
    if (OFFICAL_HTTP == mUpdateConfig.mCenterAddr.first) {
        final_url = GetOfficalAddress(mUpdateConfig.mCenterAddr.second, "H6F1IJ-C97VCK-S2C5RK-EM5308");
        navigate_url = APP_UPDATE_NAVIGATE_URL;
    }
    else if (SHARE_FOLDER == mUpdateConfig.mCenterAddr.first) {
        final_url = offline_folder;
        navigate_url = APP_UPDATE_NAVIGATE_URL;
        navigate_file = APP_UPDATE_NAVIGATE_FILE;
    }
    else {
        navigate_url = APP_UPDATE_NAVIGATE_URL;
        navigate_file = APP_UPDATE_NAVIGATE_FILE;
    }

    NavigateModel navimodel;
    std::string baseurl = GetDownloadUrl(mUpdateConfig.mCenterAddr.first,
                                           final_url,
                                           navigate_url,
                                           navimodel);
    if (baseurl.empty()) {
        if (SHARE_FOLDER == mUpdateConfig.mCenterAddr.first) {
            return 1;
        }
        else {
            return -2;
        }
    }

    LOG_GLTX("update base url is %s", baseurl.c_str());

    if (mUpdateMethod == UPDATE_NORMAL_VERSION) {

        LOG_GLTX("update UPDATE_NORMAL_VERSION");
        int err = NormalUpdateEntry(mUpdateConfig.mCenterAddr.first, folder, baseurl, navimodel, newversion);
        if (err) {
            return err;
        }
    }
    else {
        LOG_GLTX("update UPDATE_ORIGIN_VERSION");
        int err = OriginUpdateEntry(folder, baseurl, mCurrentVersion, newversion);
        if (err) {
            return err;
        }
    }
    return 0;
}

string UpdateAppEngine::GetDefaultAddress() {
    if (mUpdateMethod == UPDATE_ORIGIN_VERSION) {
        return "/ruc/esm/linux/" + mUpdateConfig.mUpdateProduct;
    }
    else {
        struct utsname uts;
        if (0 == uname(&uts)) {
            if (Utils::String::StartsWith(uts.machine, "mips")) {
                return string("/ruc/esm/linux/mips64");
            }
            return string("/ruc/esm/linux/") + uts.machine;
        }
    }
    return  "";
}

int UpdateAppEngine::OriginUpdateEntry(const string& folder, const string& baseurl, const string& version, std::string& newversion) {
    const std::string versionlist = Utils::Path::JoinPath(folder.c_str(), CLIENT_NEW_LIST_FILE, NULL);
    int err = DownloadFile(Utils::Path::JoinPath(baseurl.c_str(), CLIENT_NEW_LIST_FILE, NULL), versionlist);
    if (err) {
        return -3;
    }

    newversion = GetNewVersion(versionlist);
    LOG_GLTX("the new version is %s and current is %s", newversion.c_str(), version.c_str());
    if (newversion <= version) {
        return 1;
    }

    if (mObserver) {
        mObserver->OnUpdateEvent(UpdateObserver::UPDATE_EVENT_APP,
                                 UpdateObserver::UDDATE_GET_NEW_VERSION,
                                 &newversion);
    }

    LOG_GLTX("start to download file");
    const std::string clientzipfile = Utils::Path::JoinPath(folder.c_str(), CLIENT_MD5_LIST_FILE, NULL);
    err = DownloadFile(Utils::Path::JoinPath(baseurl.c_str(), CLIENT_MD5_LIST_FILE, NULL), clientzipfile);
    if (err) {
        return -4;
    }

    std::string clientmd5file;
    if (UnzipFile(clientzipfile, clientmd5file)) {
        return -5;
    }


    std::map<std::string, std::string> clientmd5;
    if (GetUpdateFileMd5(clientmd5file, clientmd5)) {
        return -6;
    }

    unlink(clientmd5file.c_str());

    std::vector<UPDATALISTINFO> updates;
    std::vector<std::string> updateless;
    int count = ParseVersionList(versionlist, clientmd5, updates, updateless);
    if (count < 0) {
        return -7;
    }
    unlink(versionlist.c_str());

    LOG_GLTX("download %d file", count);

    if (mObserver) {
        mObserver->OnUpdateEvent(UpdateObserver::UPDATE_EVENT_APP,
                                 UpdateObserver::UPDATE_GET_FILE_LIST,
                                 &count);
    }

    std::vector<UPDATALISTINFO>::iterator iter;
    for (iter=updates.begin(); iter!=updates.end(); ++iter) {
        if (DownloadUpdateFile(*iter, folder, baseurl)) {
            return -1;
        }


        if (mObserver) {
            mObserver->OnUpdateEvent(UpdateObserver::UPDATE_EVENT_APP,
                                     UpdateObserver::UPDATE_DOWNLOAD_FILE,
                                     iter->filelist.filename);
        }
    }
    return 0;
}

int UpdateAppEngine::NormalUpdateEntry(UPDATE_SOURCE sourcetype, const string& folder, const string& baseurl, const NavigateModel& navimodel, string& newversion) {
    string vernavi = "rec_" + navimodel.mVersion + ".xml";
    string versionurl = Utils::Path::JoinPath(baseurl.c_str(), vernavi.c_str(), NULL);
    string header, body;

    LOG_GLTX("update NormalUpdateEntry url:%s", versionurl.c_str());
    if (SHARE_FOLDER == sourcetype) {
        if (!Utils::Path::FileAvailed(versionurl)) {
            LOG_GLTX("update FileAvailed");
            return 1;
        }
    }
    GetNavigate(sourcetype, versionurl, body);
//    int err = http_get(versionurl, "", header, body);
//    if (err) {
//        return -1;
//    }

    if (IsHtmlErrorPage(body)) {
        LOG_GLTX("update IsHtmlErrorPage");
        return -1;
    }
    map<string, string> versions;
    if (GetUpdateVersion(body, newversion, versions)) {
        LOG_GLTX("update GetUpdateVersion: body:%s", body.c_str());
        return -1;
    }

	mCurrentVersion = "3.0.0.42";
    if (Utils::String::CompareVersion(mCurrentVersion, newversion) < 0) {
        if (mObserver) {
            mObserver->OnUpdateEvent(UpdateObserver::UPDATE_EVENT_APP,
                                     UpdateObserver::UDDATE_GET_NEW_VERSION,
                                     &newversion);
        }
    }
    else {
        LOG_GLTX("update CompareVersion -->(%s,%s)", mCurrentVersion.c_str(), newversion.c_str());
        return 1;
    }

    map<string, string>::iterator iter;
    for (iter=versions.begin(); iter!=versions.end(); ++iter) {
        // TODO 此处是为了应对3.0.0.19版本无法解析COMMON和TOOLS,故在此做了强制修改，以后必须得把这个改回去
        if (iter->first == "ep" || iter->first == "xav" || iter->first == "xfw") {
            if (UpdateComponent(sourcetype, iter->first, baseurl, folder)) {
                LOG_GLTX("update UpdateComponent");
                return -1;
            }
        }
    }
    return 0;
}

int UpdateAppEngine::UpdateFiles(const std::string & folder, const std::string& version) {
    LOG_GLTX("download finished");
    mCurrentVersion = version;

    // download file finish, then replace the update entry
    string update_entry = Utils::Path::JoinPath(folder.c_str(), DEPLOYED_BIN_FOLDER, UPDATE_PROCESS_ENTRY, NULL);
    if (Utils::Path::FileAvailed(update_entry)) {
        LOG_GLTX("find the GLTX2, and replace it");

        std::string backupFolder = Utils::Path::JoinPath(mInstallDir.c_str(), FOLDER_RJJH_GLTX, UPDATE_BACKUP_FOLDER, NULL);
        Utils::Path::CheckPath(backupFolder);

        // first, backup the origin file
        if (!Utils::Path::CopyFile(
                    Utils::Path::JoinPath(mInstallDir.c_str(), DEPLOYED_BIN_FOLDER, UPDATE_PROCESS_ENTRY, NULL),
                    Utils::Path::JoinPath(backupFolder.c_str(), UPDATE_PROCESS_ENTRY, NULL))) {
            Utils::Path::DeleteFolder(backupFolder.c_str());
            return -3;
        }
        // second, copy the new update entry to bin
        if (!Utils::Path::CopyFile(
                    update_entry,
                    Utils::Path::JoinPath(mInstallDir.c_str(), DEPLOYED_BIN_FOLDER, UPDATE_PROCESS_ENTRY, NULL))) {
            Utils::Path::CopyFile(
                        Utils::Path::JoinPath(backupFolder.c_str(), UPDATE_PROCESS_ENTRY, NULL),
                        Utils::Path::JoinPath(mInstallDir.c_str(), DEPLOYED_BIN_FOLDER, UPDATE_PROCESS_ENTRY, NULL));
            Utils::Path::DeleteFolder(backupFolder.c_str());
            return -3;
        }
        // third, delete the temp folder
        Utils::Path::DeleteFolder(backupFolder.c_str());
        // must delete the update entry
        unlink(update_entry.c_str());
    }
    return 0;
}

int UpdateAppEngine::UpdateComponent(UPDATE_SOURCE type, const string& name, const string& baseurl, const string& tmpfolder) {
    string navi = name + ".xml";
    string componenturl = Utils::Path::JoinPath(baseurl.c_str(), "xml", name.c_str(), navi.c_str(), NULL);
    string header, content;

    GetNavigate(type, componenturl, content);
//    if (http_get(componenturl, "", header, content)) {
//        return -1;
//    }
    LOG_GLTX("GetNavigate componenturl:%s, content:%s", componenturl.c_str(), content.c_str());
    vector<UpdateItem> details;
    if (GetComponentDetail(name, content, details)) {
        return -1;
    }

    vector<UpdateItem>::iterator iter;
    for (iter=details.begin(); iter!=details.end(); ++iter) {
        string origin = Utils::Path::JoinPath(mInstallDir.c_str(), iter->dest.c_str(), NULL);
        string hash = Utils::String::ToUpper(Utils::Hash::GetFileMD5(origin));
        if (hash != iter->md5) {
            string zipfile = iter->dest + "_" + iter->md5 + ".rz";
            string downloadurl = Utils::Path::JoinPath(baseurl.c_str(), "rz", name.c_str(), zipfile.c_str(), NULL);
            string downloadfile = Utils::Path::JoinPath(tmpfolder.c_str(), iter->dest.c_str(), NULL);

            string path, file;
            Utils::Path::SplitPath(downloadfile, path, file);
            Utils::Path::CheckPath(path);
            string downzip = Utils::Path::JoinPath(path.c_str(), (iter->name + "_" + iter->md5 + ".rz").c_str(), NULL);

            LOG_GLTX("UpdateComponent file %s to %s", downloadurl.c_str(), downzip.c_str());
            bool ret = false;
            if (SHARE_FOLDER == type) {
                ret = Utils::Path::CopyFile(downloadurl, downzip)?0:-1;
            }
            else {
                ret = DownloadFile(downloadurl, downzip);
            }
            if (ret) {
                unlink(downzip.c_str());
            }

            if (Utils::SevenZip::lzma_uncompress(downzip, downloadfile)) {
                unlink(downloadfile.c_str());
            }
            unlink(downzip.c_str());

            string newhash = Utils::String::ToUpper(Utils::Hash::GetFileMD5(downloadfile));
            if (newhash != iter->md5) {
                LOG_GLTX("download %s error", iter->dest.c_str());
                return -1;
            }

            chmod(downloadfile.c_str(), 0755);

            if (mObserver) {
                mObserver->OnUpdateEvent(UpdateObserver::UPDATE_EVENT_APP,
                                         UpdateObserver::UPDATE_DOWNLOAD_FILE,
                                         &iter->name);
            }
        }

    }
    return 0;
}

int UpdateAppEngine::GetComponentDetail(const string& name, const string& content, vector<UpdateItem>& details) {
    xmlDocPtr doc = xmlReadMemory(content.c_str(), content.size(), NULL, "UTF-8", 0);
    if (NULL == doc){
        return -1;
    }

    xmlNodePtr root = xmlDocGetRootElement(doc);
    if (NULL == root){
        xmlFreeDoc(doc);
        return -2;
    }

    string version = (const char*)xmlGetProp(root, BAD_CAST"version");
    for(xmlNodePtr ptr = root->children; ptr; ptr = ptr->next) {
        if(XML_ELEMENT_NODE != ptr->type) {
            continue;
        }
        else if (xmlStrcmp(BAD_CAST "componet",ptr->name) == 0) {
            ParseComponent(name.c_str(), ptr, details);
        }
    }

    return 0;
}

int UpdateAppEngine::GetUpdateVersion(const string& content, string& version, map<string, string>& components) {
    xmlDocPtr doc = xmlReadMemory(content.c_str(), content.size(), NULL, "UTF-8", 0);
    if (NULL == doc){
        return -1;
    }

    xmlNodePtr root = xmlDocGetRootElement(doc);
    if (NULL == root){
        xmlFreeDoc(doc);
        return -2;
    }
    xmlChar *data = xmlGetProp(root, BAD_CAST"version");
    version = (const char*)data;
    xmlFree(data);

    for(xmlNodePtr ptr = root->children; ptr; ptr = ptr->next) {
        if(XML_ELEMENT_NODE != ptr->type) {
            continue;
        }
        else if(xmlStrcmp(BAD_CAST "item",ptr->name) == 0) {
            data = xmlGetProp(ptr, BAD_CAST"name");
            string name = (const char*)data;
            xmlFree(data);
            data = xmlGetProp(ptr, BAD_CAST"version");
            string ver = (const char*)data;
            xmlFree(data);
            if (name != "common") {
                components.insert(make_pair(name, ver));
            }
        }
    }

    xmlFreeDoc(doc);
    xmlCleanupParser();
    return 0;
}

int UpdateAppEngine::ParseComponent(const char *name, xmlNodePtr node, vector<UpdateItem>& details) {
    for(xmlNodePtr ptr = node->children; ptr; ptr = ptr->next) {
        if(XML_ELEMENT_NODE != ptr->type) {
            continue;
        }
        else if (xmlStrcmp(BAD_CAST "kernel", ptr->name) == 0) {
            for(xmlNodePtr child=ptr->children; child; child=child->next) {
                if(XML_ELEMENT_NODE != child->type) {
                    continue;
                }
                else if (xmlStrcmp(BAD_CAST "file", child->name) == 0) {
                    UpdateItem item;
                    ParseUpdateItem(child, item);
                    if (!item.name.empty()) {
                        // if the kernel file match the system kernel version
                        int start = item.name.find("_");
                        int end = item.name.rfind(".ko");
                        if (start!=(int)string::npos && end!=(int)string::npos) {
                            string env = item.name.substr(start+1, end-start-1);
                            if (env == Utils::OS::GetKernelVersionString()) {
                                item.type = UpdateItem::KERNEL;
                                details.push_back(item);
                            }
                        }
                    }
                }
            }
        }
        else if (xmlStrcmp(BAD_CAST name, ptr->name) == 0) {
            for(xmlNodePtr child=ptr->children; child; child=child->next) {
                if(XML_ELEMENT_NODE != child->type) {
                    continue;
                }
                else if (xmlStrcmp(BAD_CAST "file", child->name) == 0) {
                    UpdateItem item;
                    ParseUpdateItem(child, item);
                    item.type = UpdateItem::FILE;
                    details.push_back(item);
                }
            }
        }
    }
    return 0;
}

int UpdateAppEngine::ParseUpdateItem(xmlNodePtr child, UpdateItem& item) {
    xmlChar *data = xmlGetProp(child, BAD_CAST"name");
    item.name = (const char*)data;
    xmlFree(data);
    data = xmlGetProp(child, BAD_CAST"dstpath");
    item.dest = (const char*)data;
    xmlFree(data);
    data = xmlGetProp(child, BAD_CAST"md5");
    item.md5 = (const char*)data;
    xmlFree(data);
    data = xmlGetProp(child, BAD_CAST"ver");
    item.version = (const char*)data;
    xmlFree(data);
    return 0;
}

int UpdateAppEngine::DownloadUpdateFile(const UPDATALISTINFO& info, const std::string& folder, const std::string& baseurl) {
    std::string dest = Utils::Path::JoinPath(folder.c_str(), info.filelist.filename, NULL);
    std::string path, file;
    if (Utils::Path::SplitPath(dest, path, file)) {
        Utils::Path::mkdirs(path);

        std::string url = Utils::Path::JoinPath(baseurl.c_str(), info.filelist.downname, NULL);
        std::string protocol, remotefile;
        if (!Utils::Path::SplitPath(url, protocol, remotefile)) {
            return -1;
        }

        std::string downloadfile = Utils::Path::JoinPath(path.c_str(), remotefile.c_str(), NULL);
        if (DownloadFile(url, downloadfile)) {
            return -2;
        }

        LOG_GLTX("download file %s", remotefile.c_str());

        if (Utils::Path::FileAvailed(downloadfile)) {
            std::string outfile;
            if (UnzipFile(downloadfile, outfile)) {
                return -1;
            }

            int pos = outfile.find(info.filetype);
            if (pos != -1) {
                std::string real = outfile.substr(0, pos-1);
                return rename(outfile.c_str(), real.c_str());
            }
        }
    }
    return -1;
}

