#ifndef DEFENENGINE_H
#define DEFENENGINE_H

#include <string>
#include <map>

#include "observer.h"
#include "kernelapplication.h"

using namespace std;

class DefenModProxy;
class DefenPlugins;
class StorageBridge;
class ServiceBinder;
class AntiVirusSetting;
class AppConfig;
class DefenDataContainer;

class DefenEngine : public DefenObserver, public KernelApplication {
public:
    static DefenEngine* NEW(ServiceBinder *binder, StorageBridge *storage, AppConfig *config);
    virtual ~DefenEngine();

    /**
     * @brief StartFileMonitor
     * @return 0 have matched ko, but not running, 1 running, < 0 error
     */
    int StartFileMonitor();
    int StopFileMonitor();

    int LoadFileMonitorSetting();

    list<string> &GetFolderMonitorList();


    DefenPlugins        *mFileJudge;
private:
    DefenEngine(ServiceBinder *binder, StorageBridge *storage, AppConfig *config);
    int Construct();

    inline string GetScanParams(const string& file);

protected:
    // from DefenObserver
    int onDefenEvent(DEFEN_TYPE event, const char *file, void *data=NULL);

private:
    DefenModProxy       *mDefenProxy;

    DefenDataContainer  *mDataContainer;

    map<unsigned int, int>  mScanCache;
};

#endif // DEFENENGINE_H
