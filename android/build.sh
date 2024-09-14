# ============== Настройка путей
QtPath=/home/andrey/Aqt/6.6.0/android_arm64_v8a/
QtHostPath=/home/andrey/Aqt/6.6.0/gcc_64
NdkPath=/home/andrey/Android/Sdk/ndk/25.1.8937393
SdkPath=/home/andrey/Android/Sdk
CMake=cmake

# ============== Добавляем путь до java для подписи apk
export JAVA_HOME=/usr/lib/jvm/java-19-openjdk-amd64
export PATH=$PATH:$JAVA_HOME/bin

# ============== Настройка переменных окружения для подписи пакета
export QT_ANDROID_KEYSTORE_PATH=$PWD/example.keystore
export QT_ANDROID_KEYSTORE_ALIAS=Example
export QT_ANDROID_KEYSTORE_KEY_PASS=12345678
export QT_ANDROID_KEYSTORE_STORE_PASS=12345678

## ============== Очистка папки сборки
#rm -r ./build
#mkdir build
#cd build

$CMake \
-DCMAKE_PREFIX_PATH=$QtPath/lib/cmake \
-DCMAKE_BUILD_TYPE=Release \
-DANDROID_SDK_ROOT=$SdkPath \
-DANDROID_NDK_ROOT=$NdkPath \
-DCMAKE_TOOLCHAIN_FILE=$QtPath/lib/cmake/Qt6/qt.toolchain.cmake \
-DQT_ANDROID_DEPLOY_RELEASE=ON \
-DQT_HOST_PATH=$QtHostPath \
-DQT_HOST_PATH_CMAKE_DIR=$QtHostPath/lib/cmake \
-DQT_ANDROID_SIGN_APK=ON \
..

cmake --build . --config Release --target apk -- -j30