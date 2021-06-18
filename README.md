# OpenCV Template
OpenCVを使用するための雛形です。


# 使い方
このリポジトリをクローンし、`main.cpp`を書き換えて使用します。
`include/`はインクルードディレクトリとして設定されています。
`src/`に置かれた`*.cpp`ファイルは全てCMakeが自動的に読み込んでくれます。


# 使用するモジュールの追加
OpenCVは複数のモジュールから構成されています。
`OpenCV Template`ではビルド時間を短縮するため、デフォルトで以下のモジュールのみをビルドするようになっています。

- core
- imgproc
- imgcodecs
- highgui
- videoio

使用するモジュールを追加したい場合は`CMakeLists.txt`の中の`OPENCV_BUILD_LIST`変数を適宜書き換えて下さい。


# ビルド手順
## Ubuntu or MacOS
### 必要なツールのインストール

Ubuntuの場合

```sh
sudo apt install -y git cmake
```

MacOSの場合

```sh
brew install git cmake
```

### リポジトリのクローン

```sh
git clone https://github.com/wakewakame/opencv_template
cd opencv_template
git submodule update --init --recursive
```

### ビルド

```sh
mkdir build
cd build
cmake ..
make -j
```

### 実行

```sh
./bin/opencv_template
```

## Windows
### 必要なソフトのインストール
事前に以下のソフトをインストールして下さい。

- [Visual Studio](https://visualstudio.microsoft.com/ja/downloads/)  (Visual Studio Community 2019で動作確認済み)
- [Git](http://git-scm.com/downloads)
- [CMake](https://cmake.org/download/)

### Visual Studioのソリューションファイルを生成
ファイルエクスプローラーでプロジェクトフォルダを作成したい場所を開き、アドレスバーに`cmd`と入力してコマンドプロンプトを起動します。
次に、コマンドプロンプトに以下のコマンドを入力してVisual Studioのソリューションファイルを生成します。
(1行ずつ実行することをオススメします)

```sh
git clone https://github.com/wakewakame/opencv_template
cd opencv_template
git submodule update --init --recursive
mkdir build
cd build
cmake ..
```

完了すると`opencv_template`フォルダが生成されます。
また、`opencv_template\build\opencv_template_project.sln`にVisual Studioのソリューションファイルが生成されます。

### ビルド
`opencv_template\build\opencv_template_project.sln`を開き、`opencv_template`をスタートアッププロジェクトに設定します。
F5キーを押すとビルドが開始します。
