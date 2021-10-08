import qbs 1.0
import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "MultimediaGstTools"
    Depends { name: "Qt"; submodules: ["core-private", "multimedia-private", "gui-private", "multimediawidgets"]}

    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: []
    dynamicLibsDebug: []
    dynamicLibsRelease: ["/usr/lib/libQt5MultimediaWidgets.so", "/usr/lib/libQt5Multimedia.so", "/usr/lib/libQt5Widgets.so", "/usr/lib/libQt5Gui.so", "/usr/lib/libQt5Network.so", "/usr/lib/libQt5Core.so", "pthread", "asound", "gstgl-1.0", "gstapp-1.0", "gstpbutils-1.0", "gstaudio-1.0", "gstvideo-1.0", "gstbase-1.0", "gsttag-1.0", "gstallocators-1.0", "gstreamer-1.0", "gobject-2.0", "pulse-mainloop-glib", "pulse", "glib-2.0"]
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "Qt5MultimediaGstTools"
    libNameForLinkerRelease: "Qt5MultimediaGstTools"
    libFilePathDebug: ""
    libFilePathRelease: "/usr/lib/libQt5MultimediaGstTools.so.5.15.2"
    cpp.defines: ["QT_MULTIMEDIAGSTTOOLS_LIB"]
    cpp.includePaths: ["/usr/include/qt", "/usr/include/qt/QtMultimediaGstTools", "/usr/include/qt/QtMultimediaGstTools/5.15.2", "/usr/include/qt/QtMultimediaGstTools/5.15.2/QtMultimediaGstTools"]
    cpp.libraryPaths: []
    
}
