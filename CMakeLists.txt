# CMakeの最小バージョンの指定
cmake_minimum_required(VERSION 3.10)

# プロジェクトの作成
project(opencv_template_project)

# OpenCVのパス
set(OPENCV_DIR "${PROJECT_SOURCE_DIR}/3rdparty/opencv")

# OpenCVで使用するModuleの指定
set(OPENCV_BUILD_LIST
	"core"
	"imgproc"
	"imgcodecs"
	"highgui"
	"videoio"
)
string(REGEX REPLACE ";" "," OPENCV_BUILD_LIST_STRING "${OPENCV_BUILD_LIST}")
string(REGEX REPLACE "([^;]+)" "opencv_\\1" OPENCV_BUILD_LIST_TARGET "${OPENCV_BUILD_LIST}")
string(REGEX REPLACE "([^;]+)" "${OPENCV_DIR}/modules/\\1/include" OPENCV_BUILD_LIST_INCLUDE "${OPENCV_BUILD_LIST}")

# C++17を使用する
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
find_package(Threads REQUIRED)

# compile_commands.jsonを生成するようにする
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE BOOL "generate compile_commands.json" FORCE)

# OpenCVの中で必要なモジュールのみビルドするように設定
set(BUILD_LIST "${OPENCV_BUILD_LIST_STRING}" CACHE STRING "OpenCV Build List" FORCE)

# OpenCVのCMakeLists.txtを読み込む
add_subdirectory("${OPENCV_DIR}")

# 全てのソースファイルを再帰的に検索する
file(GLOB_RECURSE ALL_CPP_FILES "${PROJECT_SOURCE_DIR}/src/*.cpp")

# メインプログラムの作成
add_executable(opencv_template "${PROJECT_SOURCE_DIR}/main.cpp" "${ALL_CPP_FILES}")
target_include_directories(opencv_template PUBLIC "${PROJECT_SOURCE_DIR}/include")

# OpenCVをライブラリとして追加
target_link_libraries(opencv_template "${OPENCV_BUILD_LIST_TARGET}")
target_include_directories(opencv_template PUBLIC
	"${CMAKE_BINARY_DIR}"
	"${OPENCV_DIR}/include"
	"${OPENCV_BUILD_LIST_INCLUDE}"
)
