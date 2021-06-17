# CMakeの最小バージョンの指定
cmake_minimum_required(VERSION 3.10)

# プロジェクトの作成
project(opencv_template_project)

# C++17を使用する
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
find_package(Threads REQUIRED)

# OpenCVの必要なモジュールのみビルドするように設定
set(BUILD_LIST "core,imgproc,imgcodecs,highgui" CACHE STRING "OpenCV Build List" FORCE)

# OpenCVのCMakeLists.txtを読み込む
set(OPENCV_DIR "${PROJECT_SOURCE_DIR}/3rdparty/opencv")
add_subdirectory("${OPENCV_DIR}")

# 全てのソースファイルを再帰的に検索する
file(GLOB_RECURSE ALL_CPP_FILES "${PROJECT_SOURCE_DIR}/src/*.cpp")

# メインプログラムの作成
add_executable(opencv_template "${PROJECT_SOURCE_DIR}/main.cpp" "${ALL_CPP_FILES}")
#target_include_directories(opencv_template PUBLIC "${PROJECT_SOURCE_DIR}/include")

# OpenCVをライブラリとして追加
target_link_libraries(opencv_template
	opencv_core
	opencv_imgcodecs
	opencv_imgproc
	opencv_highgui
)
target_include_directories(opencv_template PUBLIC
	"${CMAKE_BINARY_DIR}"
	"${OPENCV_DIR}/include"
	"${OPENCV_DIR}/modules/core/include"
	"${OPENCV_DIR}/modules/imgcodecs/include"
	"${OPENCV_DIR}/modules/imgproc/include"
	"${OPENCV_DIR}/modules/highgui/include"
)
