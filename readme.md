
 # 基于嵌入式环境的电子相框
采用QT开发技术，在物联网试验箱上实现了一个电子相框，系统上电启动后自动启动此电子相框程序。程序自动读取U盘中的所有图片，并自动按照5秒一张的时间间隔播放。图片自动在显示屏全屏显示（不能变形）。所有图片自动循环播放。如果没有插入U盘或U盘中没有图片，则界面上提示没有可播放的图片。支持jpg、jpeg、gif、png、bmp等常见格式的图片。

## 相关环境
- 开发语言：Qt
- 支持平台：嵌入式Linux系统，Ubuntu系统，ARM gcc
- 相关技术：计时器、QImage类、自定义Label类、信号和槽、线程、QDir类、QStringList类

## 代码介绍  
- 四个.cpp文件、一个.ui文件。main.cpp代表工程的main函数，mainwindows.cpp代表主窗口程序，mylabel.cpp是自定义的QLabel类，mythread.cpp是实现的来读取文件的线程类。  
- .ui文件中就是一个QLabel控件，利用此控件进行图片的展示。  
- 主要功能部分实现在mainwindows.cpp中，包含整个窗口的显示，线程的初始化与开始设置，信号的槽的连接，同时控件的更新也实现在这一部分。  
- mythread.cpp和mythread.h文件主要就是继承的QThread类，并重写run方法，在其中实现U盘的读写，并将获取的文件url在信号中发出，在mainwindows.cpp中的槽中获取并进行图片的判断有更换操作。
- mylabel.cpp和mylabel.h主要在mouseReleaseEvent事件触发时进行图片播放的暂停，也是利用信号和槽实现。  

## 编译和安装指南
交叉编译程序：  
1. 代码完成后，用命令行窗口进入工程目录下，执行qmake-arm，产生makefile文件。  
2. 编译：make，产生可执行文件QtPhotoFrame（如果之前已经编译过一次，需要先make clean）

## Authors
qiwenkaikai@qq.com
