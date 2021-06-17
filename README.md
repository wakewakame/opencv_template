# OpenCV Template
OpenCVを使用するための雛形です。

# ビルド手順
## Ubuntu
### 必要なツールのインストール

```sh
sudo apt install -y git cmake
```

### リポジトリのクローン

```sh
git clone https://github.com/wakewakame/opencv_template
```

### ビルド

```sh
cd opencv_template
mkdir build
cd build
cmake ..
make -j
```

### 実行

```sh
./bin/opencv_template
```

## MacOS
作成中

## Windows
作成中

# 使用するモジュールの追加
`CMakeLists.txt`の中の`OPENCV_BUILD_LIST`変数を適宜書き換える
