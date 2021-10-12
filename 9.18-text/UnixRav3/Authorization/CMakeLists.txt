cmake_minimum_required (VERSION 2.8)
project(Authorization)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(LIBRARY_OUTPUT_PATH ${BUILD_OUTPUT_DIRECTORY}/${BUILD_APP_VERSION}/lib)

add_definitions(-DUNIXPLATFORM -DUNIX  -D_NOUSESHM_)

add_library(
    ravauth
    STATIC
    configimpl.cpp
    cfgapiimpl.cpp
    tree.cpp
    node.cpp
    checksn.cpp
    checkvalid.cpp
    cfgmutex.cpp
    shmem.cpp 
    ravbase64.cpp
    mutex.cpp 
    hash.cpp 
    unixrscfg.cpp 
    regapi.cpp
)

include_directories(
    ./rscommon
    ../ThirdPart/include
)


