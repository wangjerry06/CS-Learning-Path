# CS-Learning-Path

我的 CS 学习路径记录仓库 —— 以**每天刷 LeetCode** 为主线，按日期归档代码、思路笔记和踩坑记录。

主语言 **C++**，配合 C/C++ 语言课的学习进度。

## 目录结构

```
CS-Learning-Path/
├── 2026-09-21/              # 按「年-月-日」归档，一天一个目录
│   └── leetcode1768.cpp     # LeetCode 1768. Merge Strings Alternately
├── .vscode/
│   └── tasks.json           # VS Code 构建任务（clang++）
├── .gitignore
└── README.md
```

**约定**

- 一天一个文件夹，用 `YYYY-MM-DD` 命名（如 `2026-09-21`）
- 文件名用题目形式：`leetcode<题号>.cpp`
- 只提交**源码和文档**：`.gitignore` 用白名单，可执行文件、`.o`、`.dSYM`、`.DS_Store` 都不会进版本库

## 编译与运行

```bash
cd 2026-09-21
clang++ -std=c++17 -Wall -Wextra -g leetcode1768.cpp -o leetcode1768
./leetcode1768                 # 然后在终端里手动输入
printf 'ab\ncde\n' | ./leetcode1768   # 或者管道喂输入
```

⚠️ **macOS 上必须用 `clang++`，不能用 `clang`。** `clang` 是 C 语言的驱动，链接时不会带上 C++ 运行时库 libc++，会报：

```
ld: symbol(s) not found for architecture arm64
"___gxx_personality_v0" / "___cxa_rethrow" referenced from ...
```

⚠️ VS Code 里按 **⇧⌘B 只编译不运行**，要看到输出得自己在终端里执行程序。

⚠️ `cin >>` 读不到输入时**不会报错**，变量会保持原值 —— 所以"没有输出"经常其实是"输入没读到"。程序里应该判一下：

```cpp
if (!(cin >> word1 >> word2)) {
    cerr << "没读到输入\n";
    return 1;
}
```

## 进度

| 日期 | 题目 | 要点 |
|---|---|---|
| 2026-09-21 | [1768. Merge Strings Alternately](https://leetcode.com/problems/merge-strings-alternately/) | 字符串交替拼接；`push_back` 追加、引用传参免拷贝、`cin` 失败检查 |

## 提交习惯

每天一次提交，message 带上日期和题号：

```
2026-09-21: LeetCode 1768 交替合并字符串
```
