cmake_minimum_required (VERSION 2.8)
project(UnixRav)

# 1.  need edit
# 设置QT的编译版本  4/5
set(QT_VERSION              5)
# 设置编译版本号
set(BUILD_APP_VERSION       3.0.0.1)
# 设置病毒库的版本号
set(BUILD_VLIB_VERSION      30.0518.0001)
# 设置 QT库的位置，为空则默认从系统路径中查打
set(QT5_LIBRARY_PATH   "/home/dong/rising/QT/9.18-text/qt-everywhere-opensource-src-5.5.0/bulid")
# 编译输出路径
set(BUILD_OUTPUT_DIRECTORY  /home/dong/rising/Source_Code/9.18-text/build)
# 是否动态加库 libudev.so 库，如果为AUTO， 则动态查找，由dlopen加载, QT采用QT的udev, UDEV则显式链接
set(USB_CHECK_TYPE          AUTO)
# 通信采用方式 0=socket,1=dbus,2=socket+ev 通信
set(COMM_TYPE            0)
# 是否为调试版本，1为打日志至相应的路径
set(DEBUG   0)
# 是否采用系统的库文件， 主要为QT库及zlib库，防止自己的库与系统的冲突
set(SYSLIB  1)
## 平台类弄，在mips64上，需链接 libidn.so
#set(PLATFORM    "x86_64")   #aarch64/mips64/nfs/x86_64/zhaoxin

## 是否为低版本的LINUX，主要为CENTOS5/i686 所制定
set(LOW_VERSION     0)

## 是否为linux编译, 如果为AIX及其它编译， 则将其置
set(LINUX_SYS    1)

#add_definitions(-DMEM_CHECK)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -O2")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc")

# 2. define the executable process name
set(RAV_NOTIFIY_APP         RAVRJJH0)
set(RAV_NOTIFIY_SEC_APP     RAVRJJH00)
set(RAV_QT_MAIN_APP         RAVRJJH2)
set(RAV_QT_SETTING_APP      RAVRJJH4)
set(RAV_QT_LOGVIEW_APP      RAVRJJH6)
set(RAV_QT_UNINSTALL_APP    RAVUninstall)
set(RAV_CONTEXT_PROXY       RAVRJJH8)
set(RAV_CONSOLE_MAIN_APP    rav.bin)
set(RAV_SETUP_APP           setup.bin)
set(RAV_UNINSTALL_APP       uninstall.bin)
set(RAV_CONSOLE_SETUP       ravsetup.bin)
set(RAV_CONSOLE_UNINSTALL   ravuninst.bin)
set(RAV_AUTO_PACK           ravautopack.bin)
set(RAV_SELF_EXTRACTER      ravextrater.bin)
set(RAV_DOWNLOADER          downloader.bin)
set(RAV_CROSS_UPDATER       crossupdater.bin)
set(RAV_PACKAGE_TOOL        PackTools)
set(RAV_UPGRADE_MAKER       UpgradeMaker)

set(RAV_DAEMON_GJCZ         RAVGJCZ0)
set(RAV_DAEMON_GLTX         RAVGLTX0)
set(RAV_DAEMON_ZDFY         RAVZDFY0)
set(RAV_DAEMON_GGFW         RAVGGFW0)
set(RAV_UPDATE              RAVGLTX2)
set(RAV_DAEMON_EDRS         RAVGJCZ2)


#
# 3.  DBUS support, if you set it true, then RPC use dbus
if(${COMM_TYPE} EQUAL 1)
    set(RPC_TYPE    COMM_WITH_DBUS)
elseif (${COMM_TYPE} EQUAL 0)
    set(RPC_TYPE    COMM_WITH_SOCKET)
elseif (${COMM_TYPE} EQUAL 2)
    set(RPC_TYPE    COMM_WITH_EV)
endif()

# 4
if(${DEBUG} EQUAL 1)
    add_definitions(-DRAV_LOG)
endif()

# 5 usb check
if(${USB_CHECK_TYPE} STREQUAL "QT")
    add_definitions(-DUSB_CHECK_BY_QT)
elseif(${USB_CHECK_TYPE} STREQUAL "UDEV")
    add_definitions(-DUSB_CHECK_BY_UDEV)
elseif(${USB_CHECK_TYPE} STREQUAL "AUTO")
    add_definitions(-DUSB_CHECK_BY_DYNAMIC)
endif()

# 6
if(${LOW_VERSION} EQUAL 1)
    add_definitions(-DLOW_LINUX_VERSION)
endif()

# 7
if(${LINUX_SYS} EQUAL 1)
    add_definitions(-DCOMMON_LINUX)
endif()

configure_file (
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_SOURCE_DIR}/config.h"
)


add_subdirectory(Authorization)
add_subdirectory(CommonAPI)
add_subdirectory(Storage)
add_subdirectory(ScanEngine)
add_subdirectory(Communicator)
add_subdirectory(DefenMod)
add_subdirectory(Netfilter)
add_subdirectory(Upgrade)
add_subdirectory(RavQt)
add_subdirectory(RavDaemon)
add_subdirectory(RavConsole)
add_subdirectory(PackageTools)
add_subdirectory(ContextMenu)
#if(${DEBUG} EQUAL 1)
#    add_subdirectory(Test)
#endif()
