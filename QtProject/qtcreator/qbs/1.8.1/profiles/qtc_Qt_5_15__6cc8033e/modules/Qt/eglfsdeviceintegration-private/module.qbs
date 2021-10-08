import qbs 1.0
import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "EglFSDeviceIntegration"
    Depends { name: "Qt"; submodules: ["core", "gui", "core-private", "gui-private", "devicediscovery_support-private", "eventdispatcher_support-private", "service_support-private", "theme_support-private", "fontdatabase_support-private", "fb_support-private", "egl_support-private", "input_support-private", "platformcompositor_support-private", "vulkan_support-private"]}

    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: []
    dynamicLibsDebug: []
    dynamicLibsRelease: ["/usr/lib/libQt5EventDispatcherSupport.a", "gthread-2.0", "glib-2.0", "/usr/lib/libQt5ServiceSupport.a", "/usr/lib/libQt5ThemeSupport.a", "/usr/lib/libQt5FontDatabaseSupport.a", "fontconfig", "freetype", "z", "/usr/lib/libQt5FbSupport.a", "/usr/lib/libQt5EglSupport.a", "EGL", "Xext", "X11", "m", "/usr/lib/libQt5InputSupport.a", "mtdev", "input", "/usr/lib/libQt5XkbCommonSupport.a", "/usr/lib/libQt5PlatformCompositorSupport.a", "/usr/lib/libQt5VulkanSupport.a", "GL", "/usr/lib/libQt5Gui.so", "/usr/lib/libQt5DeviceDiscoverySupport.a", "udev", "/usr/lib/libQt5DBus.so", "/usr/lib/libQt5Core.so", "pthread", "dl", "ts", "xkbcommon"]
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "Qt5EglFSDeviceIntegration"
    libNameForLinkerRelease: "Qt5EglFSDeviceIntegration"
    libFilePathDebug: ""
    libFilePathRelease: "/usr/lib/libQt5EglFSDeviceIntegration.so.5.15.2"
    cpp.defines: ["QT_EGLFSDEVICEINTEGRATION_LIB"]
    cpp.includePaths: ["/usr/include/qt", "/usr/include/qt/QtEglFSDeviceIntegration", "/usr/include/qt/QtEglFSDeviceIntegration/5.15.2", "/usr/include/qt/QtEglFSDeviceIntegration/5.15.2/QtEglFSDeviceIntegration"]
    cpp.libraryPaths: []
    
}
