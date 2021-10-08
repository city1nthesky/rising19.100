import qbs 1.0
import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "InputSupport"
    Depends { name: "Qt"; submodules: ["core-private", "gui-private", "devicediscovery_support-private", "xkbcommon_support-private"]}

    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: ["/usr/lib/libQt5XkbCommonSupport.a", "GL", "/usr/lib/libQt5DeviceDiscoverySupport.a", "udev", "/usr/lib/libQt5Gui.so", "/usr/lib/libQt5Core.so", "pthread", "ts", "xkbcommon", "GL", "udev", "mtdev", "input", "xkbcommon"]
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "Qt5InputSupport"
    libNameForLinkerRelease: "Qt5InputSupport"
    libFilePathDebug: ""
    libFilePathRelease: "/usr/lib/libQt5InputSupport.a"
    cpp.defines: ["QT_INPUT_SUPPORT_LIB"]
    cpp.includePaths: ["/usr/include/qt", "/usr/include/qt/QtInputSupport", "/usr/include/qt/QtInputSupport/5.15.2", "/usr/include/qt/QtInputSupport/5.15.2/QtInputSupport"]
    cpp.libraryPaths: []
    isStaticLibrary: true
}
