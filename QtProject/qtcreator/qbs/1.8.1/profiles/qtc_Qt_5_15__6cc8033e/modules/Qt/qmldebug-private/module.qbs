import qbs 1.0
import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "QmlDebug"
    Depends { name: "Qt"; submodules: ["core-private", "qml-private", "network", "packetprotocol-private"]}

    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: ["/usr/lib/libQt5Qml.so", "/usr/lib/libQt5PacketProtocol.a", "/usr/lib/libQt5Network.so", "/usr/lib/libQt5Core.so", "pthread"]
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "Qt5QmlDebug"
    libNameForLinkerRelease: "Qt5QmlDebug"
    libFilePathDebug: ""
    libFilePathRelease: "/usr/lib/libQt5QmlDebug.a"
    cpp.defines: ["QT_QMLDEBUG_LIB"]
    cpp.includePaths: ["/usr/include/qt", "/usr/include/qt/QtQmlDebug", "/usr/include/qt/QtQmlDebug/5.15.2", "/usr/include/qt/QtQmlDebug/5.15.2/QtQmlDebug"]
    cpp.libraryPaths: []
    isStaticLibrary: true
}
