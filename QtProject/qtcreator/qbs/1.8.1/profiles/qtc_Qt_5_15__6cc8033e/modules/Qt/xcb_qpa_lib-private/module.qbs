import qbs 1.0
import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "XcbQpa"
    Depends { name: "Qt"; submodules: ["core", "gui", "core-private", "gui-private", "service_support-private", "theme_support-private", "fontdatabase_support-private", "edid_support-private", "xkbcommon_support-private", "linuxaccessibility_support-private", "vulkan_support-private"]}

    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: []
    dynamicLibsDebug: []
    dynamicLibsRelease: ["/usr/lib/libQt5ServiceSupport.a", "/usr/lib/libQt5ThemeSupport.a", "/usr/lib/libQt5FontDatabaseSupport.a", "fontconfig", "freetype", "z", "/usr/lib/libQt5XkbCommonSupport.a", "/usr/lib/libQt5LinuxAccessibilitySupport.a", "/usr/lib/libQt5AccessibilitySupport.a", "/usr/lib/libQt5VulkanSupport.a", "GL", "/usr/lib/libQt5Gui.so", "/usr/lib/libQt5EdidSupport.a", "/usr/lib/libQt5DBus.so", "/usr/lib/libQt5Core.so", "pthread", "X11-xcb", "xcb-icccm", "xcb-image", "xcb-shm", "xcb-keysyms", "xcb-randr", "xcb-render-util", "xcb-render", "xcb-shape", "xcb-sync", "xcb-xfixes", "xcb-xinerama", "xcb-xkb", "xcb-xinput", "xcb", "Xext", "X11", "m", "SM", "ICE", "xkbcommon-x11", "xkbcommon", "dl"]
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "Qt5XcbQpa"
    libNameForLinkerRelease: "Qt5XcbQpa"
    libFilePathDebug: ""
    libFilePathRelease: "/usr/lib/libQt5XcbQpa.so.5.15.2"
    cpp.defines: ["QT_XCB_QPA_LIB_LIB"]
    cpp.includePaths: []
    cpp.libraryPaths: []
    
}
