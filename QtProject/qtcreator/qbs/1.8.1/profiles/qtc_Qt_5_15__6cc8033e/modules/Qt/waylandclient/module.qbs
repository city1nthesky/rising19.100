import qbs 1.0
import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "WaylandClient"
    Depends { name: "Qt"; submodules: ["core", "gui"]}

    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: []
    dynamicLibsDebug: []
    dynamicLibsRelease: ["/usr/lib/libQt5Gui.so", "/usr/lib/libQt5Core.so", "pthread", "wayland-cursor", "wayland-client"]
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "Qt5WaylandClient"
    libNameForLinkerRelease: "Qt5WaylandClient"
    libFilePathDebug: ""
    libFilePathRelease: "/usr/lib/libQt5WaylandClient.so.5.15.2"
    cpp.defines: ["QT_WAYLANDCLIENT_LIB"]
    cpp.includePaths: ["/usr/include/qt", "/usr/include/qt/QtWaylandClient"]
    cpp.libraryPaths: []
    
}
