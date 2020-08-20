# STM32F4xx_LED-Makefile
This is a learning template for Cross compilation chain.  You can learn how to use gcc-arm-none-eabi in ubuntu to compile the bin file that can be run on STM32.

## 学习平台与工具

1. Ubuntu 20.04(Win10 子系统)
2. GNU make
3. arm-none-eabi-
4. Keil_v5

## 资料文章

<a href="https://github.com/laneston/Note/blob/master/Hey_Makefile.md"> Hey Makefile！</a>

本篇文章将会用两个例子来说明 Makefile 是如何运行的，笔者用较小的篇幅来概括初学者在编写 Makefile 时会遇到的问题，这篇文章的目的就是用最直接简单有效的方式教会大家编写 Makefile。在看完这篇文章后，也能开始写自己的 Makefile 。

<a href="https://github.com/laneston/Note/blob/master/Makefile_Note.md"> 交叉编译链下STM32的Makefile</a>

文章围绕makefile文件的编写方式，向读者讲述如何在ubuntu平台上用交叉编译链 arm-none-eabi- 编译出 STM32F4xx 系列 MCU 的执行文件。文章核心在于讲述 arm-none-eabi- 在 Makefile 中的应用方式，对比于嵌入式可视编译器 keil_v5 有什么共同点，编译思维是怎样产生的，由此来完成一个简单项目 STM32F4xx_LED-Makefile 的编译工作。

## 代码使用

这个工程有两个文件夹，一个是用 Keil_v5 编写的，需要用编译器来编译；一个是基于 arm-none-eabi- 交叉编译链工具编写的。两份代码内容完全相同，区别在于启动文件，详细我已在<a href="https://github.com/laneston/Note/blob/master/Makefile_Note.md"> 交叉编译链下STM32的Makefile</a>说明。

关于Makefile版本的代码编译方式：

### 编译命令

```
make
```

### 清除编译文件

所有编译产生的文件都在 output 文件夹，清除文件只需执行以下命令：

```
make clean
```

## 声明

以上教程与代码完全开源，但不能做商用教材，如果对阁下有帮助，麻烦给颗星星，以兹鼓励。