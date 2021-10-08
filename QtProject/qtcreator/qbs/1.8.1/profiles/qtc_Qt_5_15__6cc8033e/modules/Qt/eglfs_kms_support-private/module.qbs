import qbs 1.0
import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "EglFsKmsSupport"
    Depends { name: "Qt"; submodules: ["core", "gui"]}

    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: []
    dynamicLibsDebug: []
    dynamicLibsRelease: ["/usr/lib/libQt5EglFSDeviceIntegration.so", "/usr/lib/libQt5EventDispatcherSupport.a", "gthread-2.0", "glib-2.0", "/usr/lib/libQt5ServiceSupport.a", "/usr/lib/libQt5ThemeSupport.a", "/usr/lib/libQt5FontDatabaseSupport.a", "fontconfig", "freetype", "z", "/usr/lib/libQt5FbSupport.a", "/usr/lib/libQt5EglSupport.a", "EGL", "Xext", "X11", "m", "/usr/lib/libQt5InputSupport.a", "mtdev", "input", "/usr/lib/libQt5XkbCommonSupport.a", "/usr/lib/libQt5PlatformCompositorSupport.a", "/usr/lib/libQt5VulkanSupport.a", "/usr/lib/libQt5KmsSupport.a", "GL", "/usr/lib/libQt5Gui.so", "/usr/lib/libQt5DeviceDiscoverySupport.a", "udev", "/usr/lib/libQt5EdidSupport.a", "/usr/lib/libQt5DBus.so", "/usr/lib/libQt5Core.so", "pthread", "drm", "dl", "ts", "xkbcommon"]
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "Qt5EglFsKmsSupport"
    libNameForLinkerRelease: "Qt5EglFsKmsSupport"
    libFilePathDebug: ""
    libFilePathRelease: "/usr/lib/libQt5EglFsKmsSupport.so.5.15.2"
    cpp.defines: ["QT_EGLFS_KMS_SUPPORT_LIB"]
    cpp.includePaths: []
    cpp.libraryPaths: []
    
}
