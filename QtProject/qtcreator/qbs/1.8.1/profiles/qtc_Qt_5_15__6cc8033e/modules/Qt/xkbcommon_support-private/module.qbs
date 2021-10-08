import qbs 1.0
import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "XkbCommonSupport"
    Depends { name: "Qt"; submodules: ["core-private", "gui-private"]}

    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: ["/usr/lib/libQt5Gui.so", "/usr/lib/libQt5Core.so", "pthread", "xkbcommon", "GL"]
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "Qt5XkbCommonSupport"
    libNameForLinkerRelease: "Qt5XkbCommonSupport"
    libFilePathDebug: ""
    libFilePathRelease: "/usr/lib/libQt5XkbCommonSupport.a"
    cpp.defines: ["QT_XKBCOMMON_SUPPORT_LIB"]
    cpp.includePaths: ["/usr/include/qt", "/usr/include/qt/QtXkbCommonSupport", "/usr/include/qt/QtXkbCommonSupport/5.15.2", "/usr/include/qt/QtXkbCommonSupport/5.15.2/QtXkbCommonSupport"]
    cpp.libraryPaths: []
    isStaticLibrary: true
}
