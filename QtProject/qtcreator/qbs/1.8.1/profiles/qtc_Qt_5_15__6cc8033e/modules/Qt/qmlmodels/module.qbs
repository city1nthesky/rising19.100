import qbs 1.0
import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "QmlModels"
    Depends { name: "Qt"; submodules: ["core", "qml"]}

    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: []
    dynamicLibsDebug: []
    dynamicLibsRelease: ["/usr/lib/libQt5Qml.so", "/usr/lib/libQt5Network.so", "/usr/lib/libQt5Core.so", "pthread"]
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "Qt5QmlModels"
    libNameForLinkerRelease: "Qt5QmlModels"
    libFilePathDebug: ""
    libFilePathRelease: "/usr/lib/libQt5QmlModels.so.5.15.2"
    cpp.defines: ["QT_QMLMODELS_LIB"]
    cpp.includePaths: ["/usr/include/qt", "/usr/include/qt/QtQmlModels"]
    cpp.libraryPaths: []
    
}
