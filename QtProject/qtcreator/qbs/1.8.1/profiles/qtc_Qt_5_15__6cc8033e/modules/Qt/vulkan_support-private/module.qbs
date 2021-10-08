import qbs 1.0
import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "VulkanSupport"
    Depends { name: "Qt"; submodules: ["core-private", "gui-private"]}

    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: ["/usr/lib/libQt5Gui.so", "/usr/lib/libQt5Core.so", "pthread", "GL"]
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "Qt5VulkanSupport"
    libNameForLinkerRelease: "Qt5VulkanSupport"
    libFilePathDebug: ""
    libFilePathRelease: "/usr/lib/libQt5VulkanSupport.a"
    cpp.defines: ["QT_VULKAN_SUPPORT_LIB"]
    cpp.includePaths: ["/usr/include/qt", "/usr/include/qt/QtVulkanSupport", "/usr/include/qt/QtVulkanSupport/5.15.2", "/usr/include/qt/QtVulkanSupport/5.15.2/QtVulkanSupport"]
    cpp.libraryPaths: []
    isStaticLibrary: true
}
