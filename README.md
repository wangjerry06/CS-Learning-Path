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



## 进度

| 日期 | 题目 | 要点 |
|---|---|---|
| 2026-09-21 | [1768. Merge Strings Alternately](https://leetcode.com/problems/merge-strings-alternately/) | 字符串交替拼接；`push_back` 追加、引用传参免拷贝、`cin` 失败检查 |

## 提交习惯

每天一次提交，message 带上日期和题号：

```
2026-09-21: LeetCode 1768 交替合并字符串
```
