import qbs 1.0
import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "QuickShapes"
    Depends { name: "Qt"; submodules: ["core", "gui-private", "qml", "quick-private"]}

    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: []
    dynamicLibsDebug: []
    dynamicLibsRelease: ["/usr/lib/libQt5Quick.so", "/usr/lib/libQt5QmlModels.so", "/usr/lib/libQt5Qml.so", "/usr/lib/libQt5Gui.so", "/usr/lib/libQt5Network.so", "/usr/lib/libQt5Core.so", "pthread"]
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "Qt5QuickShapes"
    libNameForLinkerRelease: "Qt5QuickShapes"
    libFilePathDebug: ""
    libFilePathRelease: "/usr/lib/libQt5QuickShapes.so.5.15.2"
    cpp.defines: ["QT_QUICKSHAPES_LIB"]
    cpp.includePaths: ["/usr/include/qt", "/usr/include/qt/QtQuickShapes", "/usr/include/qt/QtQuickShapes/5.15.2", "/usr/include/qt/QtQuickShapes/5.15.2/QtQuickShapes"]
    cpp.libraryPaths: []
    
}
