# Qt + Android + SSL

When working with Qt, Android, and SSL in Android 6 or higher applications, it is necessary to use your own crypto library.

The [android_openssl](https://github.com/KDAB/android_openssl) repository on GitHub is a modified version of the official OpenSSL repository that is designed to build OpenSSL as a shared library for Android platforms.

## How to use

To add OpenSSL in your CMake project, append the following to your project's CMakeLists.txt file, anywhere before the find_package() call for Qt5 modules:

```CMake
if(ANDROID AND ANDROID_SSL_CMAKE_PATH AND NOT ANDROID_SSL_CMAKE_PATH STREQUAL "")
  include(${ANDROID_SSL_CMAKE_PATH}/CMakeLists.txt)
else()
  message(FATAL_ERROR "SSL library not provided, provide location of SSL library via ANDROID_SSL_CMAKE_PATH variable")
endif()
```

In this example, we are using the ANDROID_SSL_CMAKE_PATH variable to provide the path to the `android_openssl` CMakeLists.txt file.

## QtCreator

Qt Creator can automatically install the necessary files from the mentioned repository: Preferences -> Devices -> Android tab -> Android OpenSSL settings -> Download OpenSSL.
