# leetcode-test-and-run

方便 leetcode 刷题的小工具

## 原因

写这个工具的最主要原因是：懒。

作为弱鸡，刷题对我来说，是件痛苦的事情。

作为一个懒人，我更喜欢一个命令搞定一切，不想一个个写测试样例。

以上就是背景，我的刷题的环境是`C++` `Linux`，用的测试框架是[Catch2](https://github.com/catchorg/Catch2)

如果你用`vim`，那更好，这里可以安利一波我的`vim`[配置](https://guanhua.ml/vimrc)。特别推荐使用一个[插件](https://github.com/ianding1/leetcode.vim)，搭配本工具食用更佳。如果你使用我的配置，已经默认有了安装了这个插件，没有也没关系，不影响刷题。

感觉周围大部分人还是共IDE的比较多，也可以完美适应哦。

## 配置

没什么需要配置的，你把文件夹`clone`或者下载到本地，然后打开`lc.cpp`，把`LeetCode`上的`Solution`类复制到`lc.cpp`中。下面的测试规则怎么写是不会教你的，老生常谈的东西，看里面的样例照葫芦画瓢就行。更多的东西请参考[这里](https://github.com/catchorg/Catch2/tree/master/examples)。

## 动手

- 如果你用`IDE`，点`run`吧。
- 如果你用`Linux`，那就先编译`tests-main.cpp`，命令是：`g++ tests-main.cpp -c`。然后每次运行：`g++ tests-main.o lc.cpp -o lc`。
- 如果你和我一样懒，我写了`makefile`，`make`一下吧。第一遍会比较慢，之后会快很多。比较恶心的是，你要这么执行`./build/linux/x86_64/release/lc`。

## 可能遇到的问题

1. 报错了，检查一下用的是不是`C++11`。
2. 提示找不到`<bits/std++.h>`？有的编译器不支持，你可以[下载](https://gist.github.com/eduarc/6022859/raw/3f81acf4e2288d9dea02bd8a7c7a2908bbaeebbe/stdc++.h)一个放在文件夹里。把`#include <bits/stdc++.h>`换成`#include "stdc++.h"`。
3. 其他稀奇古怪的问题，开`issue`吧。

