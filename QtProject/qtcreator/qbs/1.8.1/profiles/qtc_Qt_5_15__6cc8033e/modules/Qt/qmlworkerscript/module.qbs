import qbs 1.0
import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "QmlWorkerScript"
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
    libNameForLinkerDebug: "Qt5QmlWorkerScript"
    libNameForLinkerRelease: "Qt5QmlWorkerScript"
    libFilePathDebug: ""
    libFilePathRelease: "/usr/lib/libQt5QmlWorkerScript.so.5.15.2"
    cpp.defines: ["QT_QMLWORKERSCRIPT_LIB"]
    cpp.includePaths: ["/usr/include/qt", "/usr/include/qt/QtQmlWorkerScript"]
    cpp.libraryPaths: []
    
}
