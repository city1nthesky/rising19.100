import qbs 1.0
import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "MultimediaQuick"
    Depends { name: "Qt"; submodules: ["core", "quick", "multimedia-private"]}

    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: []
    dynamicLibsDebug: []
    dynamicLibsRelease: ["/usr/lib/libQt5Multimedia.so", "/usr/lib/libQt5Quick.so", "/usr/lib/libQt5Gui.so", "/usr/lib/libQt5QmlModels.so", "/usr/lib/libQt5Qml.so", "/usr/lib/libQt5Network.so", "/usr/lib/libQt5Core.so", "pthread", "pulse-mainloop-glib", "pulse", "glib-2.0"]
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "Qt5MultimediaQuick"
    libNameForLinkerRelease: "Qt5MultimediaQuick"
    libFilePathDebug: ""
    libFilePathRelease: "/usr/lib/libQt5MultimediaQuick.so.5.15.2"
    cpp.defines: ["QT_QTMULTIMEDIAQUICKTOOLS_LIB"]
    cpp.includePaths: ["/usr/include/qt", "/usr/include/qt/QtMultimediaQuick", "/usr/include/qt/QtMultimediaQuick/5.15.2", "/usr/include/qt/QtMultimediaQuick/5.15.2/QtMultimediaQuick"]
    cpp.libraryPaths: []
    
}
