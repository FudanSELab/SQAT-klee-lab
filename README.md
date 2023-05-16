# SQAT-klee-lab

你可以通过 ghcr.io 获得该 lab 镜像：

```bash
docker login ghcr.io

docker pull ghcr.io/fudanselab/sqat-klee-lab:master

docker run --name klee -p 35022:22 -itd ghcr.io/fudanselab/sqat-klee-lab:master

docker exec -it klee bash

cd demo && make all
```

你可以直接构建 docker image：

```bash
./script/build-image.sh

./script/run-docker.sh

docker exec -it klee bash

cd demo && make all
```

## 1. tasks

1. symbolic.c 是一份用于测试 klee 的文件。尝试运行 klee 来找出 symbolic.c 文件中的简单错误。
2. 编译 fs.c 并执行；再使用 klee 尝试找出 fs.c 文件中 main 函数里的错误，并执行 klee 生成的测试用例。
3. 编译 bst.c 并执行；再使用 klee 尝试找出 bst.c 文件中的错误，并修复 bst.c 使之符合正常人类的预期。

## 2. preliminaries

[Klee](https://github.com/klee/klee) 是一种基于 LLVM bc 的动态符号执行工具。

* “基于 LLVM bc” 在于 klee 可以将 llvm bc 作为执行引擎的输入；
* “动态” 在于 klee 会倾向更高的覆盖率，会尝试执行路径中的各个 “限制条件” 的正反两面，再根据 “限制条件” 们解析出不同的、满足不同路径的 “符号值”。

可以在 http://klee.github.io/tutorials/ 这里学习 klee 的应用，可以在 http://www.doc.ic.ac.uk/~cristic/papers/klee-osdi-08.pdf 了解 klee 的实现原理、对文件系统的抽象以及对 command args / files 的符号化方式。

## 3. deliveries

1. 报告：
   1. klee 对 symbolic.c 生成文件的执行结果 (10%)；
   2. 使用 klee 从 fs.c 中找出 bug 的方式，以及 klee 生成的测试用例在 fs.c 上的执行结果 (50%)；
   3. 使用 klee 从 bst.c 中找出 bug 的方式，以及对 bst.c 的修复结果 (40%)。
2. 学习笔记 (optional, 也不计分)：
   1. 动态符号执行如何进行限制条件的求解（
   2. klee 的使用心得，klee 执行后生成文件的作用（
   3. 其他（
