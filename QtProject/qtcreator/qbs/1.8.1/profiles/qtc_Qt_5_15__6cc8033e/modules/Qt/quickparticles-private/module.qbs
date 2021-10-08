import qbs 1.0
import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "QuickParticles"
    Depends { name: "Qt"; submodules: ["core-private", "gui-private", "qml-private", "quick-private"]}

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
    libNameForLinkerDebug: "Qt5QuickParticles"
    libNameForLinkerRelease: "Qt5QuickParticles"
    libFilePathDebug: ""
    libFilePathRelease: "/usr/lib/libQt5QuickParticles.so.5.15.2"
    cpp.defines: ["QT_QUICKPARTICLES_LIB"]
    cpp.includePaths: ["/usr/include/qt", "/usr/include/qt/QtQuickParticles", "/usr/include/qt/QtQuickParticles/5.15.2", "/usr/include/qt/QtQuickParticles/5.15.2/QtQuickParticles"]
    cpp.libraryPaths: []
    
}
