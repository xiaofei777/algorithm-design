# 汉诺塔问题实验项目

## 项目简介

本项目实现了算法设计与分析课程的第一次实验内容，包括汉诺塔问题的递归与非递归算法，以及组合问题的分治策略实现。

## 项目结构

```
第一次实验/
├── README.md                  # 项目文档（本文件）
├── src/                       # 源代码目录
│   ├── hanoi_recursive.c      # 汉诺塔递归算法
│   ├── hanoi_iterative.c      # 汉诺塔非递归算法
│   └── combination.c          # 组合问题算法
├── bin/                       # 可执行文件目录
│   ├── hanoi_recursive        # 递归算法可执行文件
│   ├── hanoi_iterative        # 非递归算法可执行文件
│   └── combination            # 组合问题可执行文件
└── docs/                      # 文档目录
    ├── 第一次实验.md          # 实验要求文档
    └── 算法设计思想.md        # 算法设计思想说明
```

## 运行环境

- 操作系统：macOS / Linux / Windows
- 编译器：GCC (GNU Compiler Collection)

## 运行教程

### 1. 准备工作

打开终端，进入项目目录：

```bash
cd /Users/cfy/Documents/算法设计与分析实验/第一次实验
```

### 2. 编译程序

#### 方法一：使用 Makefile（推荐）

```bash
make
```

#### 方法二：手动一次性编译所有程序

```bash
cd src
gcc -o ../bin/hanoi_recursive hanoi_recursive.c
gcc -o ../bin/hanoi_iterative hanoi_iterative.c
gcc -o ../bin/combination combination.c
cd ..
```

#### 方法三：分别编译

根据需要选择要编译的程序。

### 使用 Makefile 快速运行

编译完成后，可以使用以下命令快速运行程序：

```bash
make run-hanoi-recursive   # 运行递归汉诺塔
make run-hanoi-iterative   # 运行非递归汉诺塔
make run-combination       # 运行组合问题
```

清理可执行文件：

```bash
make clean
```

### 3. 运行程序

#### 运行递归汉诺塔程序

```bash
./bin/hanoi_recursive
```

#### 运行非递归汉诺塔程序

```bash
./bin/hanoi_iterative
```

#### 运行组合问题程序

```bash
./bin/combination
```

### 4. 修改参数

如需修改程序参数，请编辑对应的源文件：

#### 修改汉诺塔盘子数量

编辑 `src/hanoi_recursive.c` 或 `src/hanoi_iterative.c`，找到 `main` 函数中的：

```c
int n = 4;
```

将 `4` 修改为你想要的盘子数量。

#### 修改组合问题的参数

编辑 `src/combination.c`，找到 `main` 函数中的：

```c
int n = 5, r = 3;
```

将 `n` 和 `r` 修改为你想要的值（n为总数，r为选取个数）。

## 程序说明

### 1. 汉诺塔递归算法 (src/hanoi_recursive.c)

**算法思想**：
- 将n个盘子从A移到C，分为三步：
  1. 将n-1个盘子从A移到B（借助C）
  2. 将第n个盘子从A移到C
  3. 将n-1个盘子从B移到C（借助A）

**时间复杂度**：O(2^n)
**空间复杂度**：O(n)

### 2. 汉诺塔非递归算法 (src/hanoi_iterative.c)

**算法思想**：
- 使用栈模拟递归过程
- 每个栈帧保存当前问题参数和执行步骤
- 通过栈的后进先出特性实现与递归相同的执行顺序

### 3. 组合问题 (src/combination.c)

**算法思想**：
- 采用分治策略递归实现
- 每个组合分为两种情况：包含第n个数或不包含第n个数
- 递归缩小问题规模直到r=0时输出结果

## 示例输出

### N=4汉诺塔输出

```
Hanoi Tower with 4 disks:
Move disk 1 from A to B
Move disk 2 from A to C
Move disk 1 from B to C
Move disk 3 from A to B
Move disk 1 from C to A
Move disk 2 from C to B
Move disk 1 from A to B
Move disk 4 from A to C
Move disk 1 from B to C
Move disk 2 from B to A
Move disk 1 from C to A
Move disk 3 from B to C
Move disk 1 from A to B
Move disk 2 from A to C
Move disk 1 from B to C
```

### n=5, r=3组合输出

```
Combinations of 5 numbers taken 3 at a time:
1 2 3 
1 2 4 
1 2 5 
1 3 4 
1 3 5 
1 4 5 
2 3 4 
2 3 5 
2 4 5 
3 4 5 
```

## 实验报告要点

### 数据结构说明

1. **汉诺塔递归**：使用函数调用栈，无需显式数据结构
2. **汉诺塔非递归**：使用自定义栈结构 `StackFrame`，包含 n、from、to、aux、step 字段
3. **组合问题**：使用动态数组存储原始数据和临时组合结果

### 模块接口

- `void hanoi(int n, char from, char to, char aux)` - 递归汉诺塔函数
- `void iterativeHanoi(int n, char from, char to, char aux)` - 非递归汉诺塔函数
- `void combination(int arr[], int start, int n, int r, int temp[], int index)` - 组合递归函数
- `void printCombinations(int n, int r)` - 组合输出函数

## 思考题解答

1. **时间复杂度**：汉诺塔递归算法时间复杂度为O(2^n)，每次调用分解为两个子问题
2. **非递归算法**：已在 `hanoi_iterative.c` 中实现
3. **组合问题**：已在 `combination.c` 中实现分治策略的递归算法
4. **受限汉诺塔问题**：可通过修改移动规则实现，每次移动必须经过B柱
