import qbs 1.0
import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "WaylandCompositor"
    Depends { name: "Qt"; submodules: ["core", "gui", "quick", "qml"]}

    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: []
    dynamicLibsDebug: []
    dynamicLibsRelease: ["/usr/lib/libQt5Quick.so", "/usr/lib/libQt5Gui.so", "/usr/lib/libQt5QmlModels.so", "/usr/lib/libQt5Qml.so", "/usr/lib/libQt5Network.so", "/usr/lib/libQt5Core.so", "pthread", "wayland-server", "xkbcommon"]
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "Qt5WaylandCompositor"
    libNameForLinkerRelease: "Qt5WaylandCompositor"
    libFilePathDebug: ""
    libFilePathRelease: "/usr/lib/libQt5WaylandCompositor.so.5.15.2"
    cpp.defines: ["QT_WAYLANDCOMPOSITOR_LIB"]
    cpp.includePaths: ["/usr/include/qt", "/usr/include/qt/QtWaylandCompositor"]
    cpp.libraryPaths: []
    
}
