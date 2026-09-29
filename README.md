# CS-Learning-Path

我的 CS 学习路径记录仓库 —— 以**每天刷 LeetCode** 为主线，按日期归档代码、思路笔记和踩坑记录。

主语言 **C++**，配合 C/C++ 语言课的学习进度。

## 目录结构

```
CS-Learning-Path/
├── 2026-09-21/              # 按「年-月-日」归档，一天一个目录
│   ├── leetcode1768.cpp     # LeetCode 1768. Merge Strings Alternately
│   └── 2026-09-21.md        # 当天笔记
├── 2026-09-22/
│   ├── leetcode28.cpp       # LeetCode 28. Find the Index of the First Occurrence in a String
│   ├── leetcode389.cpp      # LeetCode 389. Find the Difference
│   ├── leetcode459.cpp      # LeetCode 459. Repeated Substring Pattern
│   └── 2026-09-22.md        # 当天笔记
├── 2026-09-23/
│   ├── leetcode283.cpp      # LeetCode 283. Move Zeroes
│   └── 2026-09-23.md        # 当天笔记
├── 2026-09-24/
│   ├── leetcode1502.cpp     # LeetCode 1502. Can Make Arithmetic Progression From Sequence
│   ├── leetcode1822.cpp     # LeetCode 1822. Sign of the Product of an Array
│   └── 2026-09-24.md        # 当天笔记
├── 2026-09-25/
│   ├── leetcode896.cpp      # LeetCode 896. Monotonic Array
│   └── 2026.09.25.md        # 当天笔记
├── 2026-09-26/
│   ├── leetcode13.cpp       # LeetCode 13. Roman to Integer
│   ├── lectrue-reverse.cpp  # 讲义练习：链表逆序（先建表，再按索引倒着回填）
│   └── 2026.09.26.md        # 当天笔记
├── 2026-09-27/
│   ├── leetcode58.cpp       # LeetCode 58. Length of Last Word
│   ├── leetcode206.cpp      # LeetCode 206. Reverse Linked List
│   └── 2026-09-27.md        # 当天笔记
├── 2026-09-28/
│   ├── 2026-09-28.md        # 当天笔记
│   └── 链表十大经典算法/      # 按专题建子目录
│       ├── 链表十大经典算法.md  # 专题闯关手册（十题清单）
│       ├── leetcode141.cpp  # LeetCode 141. Linked List Cycle
│       ├── leetcode142.cpp  # LeetCode 142. Linked List Cycle II
│       ├── leetcode206.cpp  # LeetCode 206. Reverse Linked List
│       └── leetcode876.cpp  # LeetCode 876. Middle of the Linked List
├── 2026-09-29/
│   ├── 2026-09-29.md        # 当天笔记
│   └── 链表十大算法第二天/
│       ├── 链表十大经典算法_副本.md  # 专题手册（副本）
│       ├── leetcode21.cpp       # LeetCode 21. Merge Two Sorted Lists
│       ├── leetcode21_raii.cpp  # 21 的 RAII 版（List 管家类 + 自动析构）
│       └── leetcode23.cpp       # LeetCode 23. Merge k Sorted Lists
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
./leetcode1768                        # 然后在终端里手动输入
printf 'ab\ncde\n' | ./leetcode1768   # 或者管道喂输入
```

## 进度

| 日期 | 题目 |
|---|---|
| 2026-09-21 | [1768. Merge Strings Alternately](https://leetcode.com/problems/merge-strings-alternately/) |
| 2026-09-22 | [28. Find the Index of the First Occurrence in a String](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/)、[389. Find the Difference](https://leetcode.com/problems/find-the-difference/)、[459. Repeated Substring Pattern](https://leetcode.com/problems/repeated-substring-pattern/) |
| 2026-09-23 | [283. Move Zeroes](https://leetcode.com/problems/move-zeroes/) |
| 2026-09-24 | [1502. Can Make Arithmetic Progression From Sequence](https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/)、[1822. Sign of the Product of an Array](https://leetcode.com/problems/sign-of-the-product-of-an-array/) |
| 2026-09-25 | [896. Monotonic Array](https://leetcode.com/problems/monotonic-array/) |
| 2026-09-26 | [13. Roman to Integer](https://leetcode.com/problems/roman-to-integer/) |
| 2026-09-27 | [58. Length of Last Word](https://leetcode.com/problems/length-of-last-word/)、[206. Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/) |
| 2026-09-28 | [141. Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)、[142. Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/)、[876. Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/)、[206. Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)（专题复写） |
| 2026-09-29 | [21. Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)、[23. Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/) |

## 提交习惯

每天一次提交，message 带上日期和题号：

```
2026-09-21: LeetCode 1768 交替合并字符串
```
