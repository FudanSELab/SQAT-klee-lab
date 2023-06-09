# SQAT-klee-lab

Klee 是由 Stanford University 自主研发的一款全新动态符号执行工具。工具运行在一个被称作「LLVM BC」的输入文件上，在这里，被工具选中的路径将被授予「ktest」，导引测试用例。在这个 lab 里，你将使用 klee 对 3 个文件进行分析，得到一系列输出。

你可以选择在 docker 中完成 lab：

```bash
./script/build-image.sh

./script/run-docker.sh

docker exec -it klee bash

cd demo && make all
```

或者你可以选择源码安装 klee，详见 [build-klee-from-source](http://klee.github.io/build-llvm11/)。

## 1. tasks

1. symbolic.c 是一份用于测试 klee 的文件。尝试运行 klee 来找出 symbolic.c 文件中的简单错误。
2. 编译 maze.c 并执行；再使用 klee 执行 maze 程序，执行 klee 为其生成的测试用例，并根据错误的测试用例尝试找出 maze.c 中的逻辑错误。
3. 编译 bst.c 并执行；再使用 klee 尝试找出 bst.c 文件中的错误，并修复 bst.c 使之符合正常人类的预期。

## 2. preliminaries

[Klee](https://github.com/klee/klee) 是一种基于 LLVM bc 的动态符号执行工具。

* “基于 LLVM bc” 在于 klee 可以将 llvm bc 作为执行引擎的输入；
* “动态” 在于 klee 会倾向更高的覆盖率，会尝试执行路径中的各个 “限制条件” 的正反两面，再根据 “限制条件” 们解析出不同的、满足不同路径的 “符号值”。

可以在 http://klee.github.io/tutorials/ 这里学习 klee 的应用，可以在 http://www.doc.ic.ac.uk/~cristic/papers/klee-osdi-08.pdf 了解 klee 的实现原理、对文件系统的抽象以及对 command args / files 的符号化方式。

## 3. deliveries

1. 报告：
   1. klee 对 symbolic.c 生成文件的执行结果 (10%)；
   2. klee 对 maze.c 生成文件的执行结果，klee 生成的测试用例在 maze.c 上的执行结果，以及根据测试用例找出的 maze.c 的逻辑错误 (50%)；
   3. 使用 klee 从 bst.c 中找出 bug 的方式，以及对 bst.c 的修复结果 (40%)。
2. 学习笔记 (optional, 也不计分)：
   1. 动态符号执行如何进行限制条件的求解（
   2. klee 的使用心得，klee 执行后生成文件的作用（
   3. 其他（
