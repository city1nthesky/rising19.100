cmake_minimum_required (VERSION 2.6)
project(Tools)

add_subdirectory(PackTools)
add_subdirectory(AutoUpdate)
add_subdirectory(AutoRepairMaker)

#add_subdirectory(UpgradeMaker)
#add_subdirectory(AutoPack)
add_subdirectory(Downloader)
#add_subdirectory(Extracter)
add_subdirectory(CrossUpdater)
add_subdirectory(CompileTool)
add_subdirectory(QuantineRestore)
add_subdirectory(FanotifyExec)
#add_subdirectory(UnpackRpk)
