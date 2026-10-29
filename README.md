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
├── 2026-09-30/
│   ├── 2026-09-30.md        # 当天笔记
│   └── 链表十大经典算法第三天/
│       ├── 链表十大经典算法_副本2.md  # 专题手册（副本 2）
│       ├── leetcode19.cpp       # LeetCode 19. Remove Nth Node From End of List
│       ├── leetcode160.cpp      # LeetCode 160. Intersection of Two Linked Lists
│       └── leetcode160_fixed.cpp  # 160 修复版（带 FIX 注释对照）
├── 2026-10-01/
│   ├── 2026-10-01.md        # 当天笔记
│   └── 2026-10-01/
│       ├── 链表十大经典算法_副本3.md  # 专题手册（副本 3，十题全部 Done）
│       ├── leetcode234.cpp  # LeetCode 234. Palindrome Linked List
│       └── leetcode25.cpp   # LeetCode 25. Reverse Nodes in k-Group
├── 2026-10-02/
│   ├── leetcode682.cpp      # LeetCode 682. Baseball Game
│   ├── leetcode709.cpp      # LeetCode 709. To Lower Case
│   └── 2026.10.02.md        # 当天笔记
├── 2026-10-03/
│   ├── leetcode1275.cpp     # LeetCode 1275. Find Winner on a Tic Tac Toe Game
│   ├── leetcode657.cpp      # LeetCode 657. Robot Return to Origin
│   └── 2026.10.03.md        # 当天笔记
├── 2026-10-04/
│   ├── leetcode1041.cpp     # LeetCode 1041. Robot Bounded In Circle
│   ├── leetcode1672.cpp     # LeetCode 1672. Richest Customer Wealth
│   └── 2026-10-04.md        # 当天笔记
├── 2026-10-05/
│   ├── leetcode54.cpp       # LeetCode 54. Spiral Matrix
│   ├── leetcode1572.cpp     # LeetCode 1572. Matrix Diagonal Sum
│   └── 2026-10-05.md        # 当天笔记
├── 2026-10-06/
│   ├── leetcode73.cpp       # LeetCode 73. Set Matrix Zeroes
│   ├── leetcode860.cpp      # LeetCode 860. Lemonade Change
│   ├── leetcode1491.cpp     # LeetCode 1491. Average Salary Excluding the Minimum and Maximum Salary
│   └── leetcode1523.cpp     # LeetCode 1523. Count Odd Numbers in an Interval Range
├── 2026-10-07/
│   ├── 2026-10-07.md        # 当天笔记
│   ├── leetcode976.cpp      # LeetCode 976. Largest Perimeter Triangle
│   ├── leetcode976_fixed.cpp    # 976 修正版（先排序 + 用 int 索引，避免 size_t 下溢）
│   ├── leetcode1232.cpp     # LeetCode 1232. Check If It Is a Straight Line
│   ├── leetcode1232_fixed.cpp   # 1232 修正版（交叉相乘判共线，避开除法）
│   └── binary_decimal_convert.cpp  # 二进制 <-> 十进制互转示例（手动/bitset/to_chars/from_chars）
├── 2026-10-08/
│   ├── 2026-10-08.md        # 当天笔记
│   ├── leetcode43.cpp       # LeetCode 43. Multiply Strings
│   └── leetcode67.cpp       # LeetCode 67. Add Binary
├── 2026-10-09/
│   ├── leetcode50.cpp       # LeetCode 50. Pow(x, n)
│   └── 2026-10-09.md        # 当天笔记
├── 2026-10-10/
│   ├── leetcode2.cpp        # LeetCode 2. Add Two Numbers
│   ├── leetcode445.cpp      # LeetCode 445. Add Two Numbers II
│   └── 2026-10-10.md        # 当天笔记
├── 2026-10-11/
│   └── leetcode1.cpp        # LeetCode 1. Two Sum
├── 2026-10-12/
│   ├── 2026-10-12.md        # 当天笔记
│   ├── leetcode49.cpp       # LeetCode 49. Group Anagrams（含自测 check() 用例）
│   └── leetcode128.cpp      # LeetCode 128. Longest Consecutive Sequence
├── 2026-10-13/
│   ├── 2026-10-13.md        # 当天笔记
│   └── leetcode11.cpp       # LeetCode 11. Container With Most Water
├── 2026-10-14/
│   ├── 2026-10-14.md        # 当天笔记
│   ├── leetcode15.cpp       # LeetCode 15. 3Sum
│   └── leetcode303.cpp      # LeetCode 303. Range Sum Query - Immutable
├── 2026-10-15/
│   ├── leetcode3.cpp        # LeetCode 3. Longest Substring Without Repeating Characters
│   └── leetcode42.cpp       # LeetCode 42. Trapping Rain Water
├── 2026-10-16/
│   └── leetcode438.cpp      # LeetCode 438. Find All Anagrams in a String
├── 2026-10-17/
│   └── leetcode560.cpp      # LeetCode 560. Subarray Sum Equals K
├── 2026-10-18/
│   ├── leetcode239.cpp      # LeetCode 239. Sliding Window Maximum
│   └── 2026-10-18.md        # 当天笔记
├── 2026-10-19/
│   └── LCR170.cpp           # LCR 170. 交易逆序对的总数
├── 2026-10-20/
│   ├── leetcode88.cpp       # LeetCode 88. Merge Sorted Array
│   └── p1256_副本.cpp       # 有效的括号（栈实现；文件名沿用旧名，内容为 LeetCode 20）
├── 2026-10-21/
│   ├── leetcode26.cpp       # LeetCode 26. Remove Duplicates from Sorted Array
│   ├── leetcode27.cpp       # LeetCode 27. Remove Element
│   ├── p1257.cpp            # LeetCode 150. Evaluate Reverse Polish Notation（文件名沿用旧名）
│   ├── p1258.cpp            # LeetCode 1. Two Sum（排序 + 双指针；文件名沿用旧名）
│   └── p1259.cpp            # LCR 170. 交易逆序对的总数（归并统计逆序对，复写；文件名沿用旧名）
├── 2026-10-22/
│   ├── leetcode53.cpp       # LeetCode 53. Maximum Subarray（递归版，从末尾往前推以 i 结尾的最大和）
│   └── leetcode53better.cpp # 53 的分治写法（Status 四元组 pushUp 合并）
├── 2026-10-23/
│   └── leetcode80.cpp       # LeetCode 80. Remove Duplicates from Sorted Array II
├── 2026-10-24/
│   ├── leetcode104.cpp      # LeetCode 104. Maximum Depth of Binary Tree
│   ├── leetcode226.cpp      # LeetCode 226. Invert Binary Tree
│   ├── leetcode700.cpp      # LeetCode 700. Search in a Binary Search Tree
│   ├── leetcode98.cpp       # LeetCode 98. Validate Binary Search Tree
│   ├── p1261.cpp            # LeetCode 701. Insert into a Binary Search Tree（ACM 输入版；文件名沿用旧名）
│   └── p1261_fixed.cpp      # 701 修正版（1-based 哨兵 + 迭代下降；文件名沿用旧名）
├── 2026-10-25/
│   └── leetcode169.cpp      # LeetCode 169. Majority Element
├── 2026-10-26/
│   ├── leetcode21.cpp       # LeetCode 21. Merge Two Sorted Lists（链式递归版，复写）
│   ├── leetcode50.cpp       # LeetCode 50. Pow(x, n)（快速幂递归，复写；负数指数转 long long）
│   ├── leetcode100.cpp      # LeetCode 100. Same Tree
│   ├── leetcode121.cpp      # LeetCode 121. Best Time to Buy and Sell Stock（维护历史最低价）
│   ├── leetcode189.cpp      # LeetCode 189. Rotate Array（三次 reverse）
│   └── leetcode912.cpp      # LeetCode 912. Sort an Array（手写快排，取中位为 pivot）
├── 2026-10-27/
│   └── leetcode200.cpp      # LeetCode 200. Number of Islands（DFS 淹没岛屿）
├── 2026-10-28/
│   ├── leetcode122.cpp      # LeetCode 122. Best Time to Buy and Sell Stock II（贪心，累加所有上涨区间）
│   └── leetcode55.cpp       # LeetCode 55. Jump Game（维护最远可达下标）
├── 2026-10-29/
│   ├── leetcode45.cpp       # LeetCode 45. Jump Game II（按层贪心，走到当前层边界才计数）
│   └── leetcode274.cpp      # LeetCode 274. H-Index（排序后从高位往下数，遇不满足即停）
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
| 2026-09-30 | [19. Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)、[160. Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/) |
| 2026-10-01 | [234. Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/)、[25. Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/) |
| 2026-10-02 | [682. Baseball Game](https://leetcode.com/problems/baseball-game/)、[709. To Lower Case](https://leetcode.com/problems/to-lower-case/) |
| 2026-10-03 | [1275. Find Winner on a Tic Tac Toe Game](https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/)、[657. Robot Return to Origin](https://leetcode.com/problems/robot-return-to-origin/) |
| 2026-10-04 | [1041. Robot Bounded In Circle](https://leetcode.com/problems/robot-bounded-in-circle/)、[1672. Richest Customer Wealth](https://leetcode.com/problems/richest-customer-wealth/) |
| 2026-10-05 | [54. Spiral Matrix](https://leetcode.com/problems/spiral-matrix/)、[1572. Matrix Diagonal Sum](https://leetcode.com/problems/matrix-diagonal-sum/) |
| 2026-10-06 | [73. Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/)、[860. Lemonade Change](https://leetcode.com/problems/lemonade-change/)、[1491. Average Salary Excluding the Minimum and Maximum Salary](https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/)、[1523. Count Odd Numbers in an Interval Range](https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/) |
| 2026-10-07 | [976. Largest Perimeter Triangle](https://leetcode.com/problems/largest-perimeter-triangle/)、[1232. Check If It Is a Straight Line](https://leetcode.com/problems/check-if-it-is-a-straight-line/) |
| 2026-10-08 | [43. Multiply Strings](https://leetcode.com/problems/multiply-strings/)、[67. Add Binary](https://leetcode.com/problems/add-binary/) |
| 2026-10-09 | [50. Pow(x, n)](https://leetcode.com/problems/powx-n/) |
| 2026-10-10 | [2. Add Two Numbers](https://leetcode.com/problems/add-two-numbers/)、[445. Add Two Numbers II](https://leetcode.com/problems/add-two-numbers-ii/) |
| 2026-10-11 | [1. Two Sum](https://leetcode.com/problems/two-sum/) |
| 2026-10-12 | [49. Group Anagrams](https://leetcode.com/problems/group-anagrams/)、[128. Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/) |
| 2026-10-13 | [11. Container With Most Water](https://leetcode.com/problems/container-with-most-water/) |
| 2026-10-14 | [15. 3Sum](https://leetcode.com/problems/3sum/)、[303. Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/) |
| 2026-10-15 | [3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)、[42. Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/) |
| 2026-10-16 | [438. Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/) |
| 2026-10-17 | [560. Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/) |
| 2026-10-18 | [239. Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/) |
| 2026-10-19 | [LCR 170. 交易逆序对的总数](https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/) |
| 2026-10-20 | [88. Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/)、[20. Valid Parentheses](https://leetcode.com/problems/valid-parentheses/) |
| 2026-10-21 | [26. Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)、[27. Remove Element](https://leetcode.com/problems/remove-element/)、[150. Evaluate Reverse Polish Notation](https://leetcode.com/problems/evaluate-reverse-polish-notation/)、[1. Two Sum](https://leetcode.com/problems/two-sum/)、[LCR 170. 交易逆序对的总数](https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/)（归并复写） |
| 2026-10-22 | [53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/) |
| 2026-10-23 | [80. Remove Duplicates from Sorted Array II](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/) |
| 2026-10-24 | [104. Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)、[226. Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/)、[700. Search in a Binary Search Tree](https://leetcode.com/problems/search-in-a-binary-search-tree/)、[98. Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)、[701. Insert into a Binary Search Tree](https://leetcode.com/problems/insert-into-a-binary-search-tree/) |
| 2026-10-25 | [169. Majority Element](https://leetcode.com/problems/majority-element/) |
| 2026-10-26 | [21. Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)、[50. Pow(x, n)](https://leetcode.com/problems/powx-n/)、[100. Same Tree](https://leetcode.com/problems/same-tree/)、[121. Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)、[189. Rotate Array](https://leetcode.com/problems/rotate-array/)、[912. Sort an Array](https://leetcode.com/problems/sort-an-array/) |
| 2026-10-27 | [200. Number of Islands](https://leetcode.com/problems/number-of-islands/) |
| 2026-10-28 | [122. Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)、[55. Jump Game](https://leetcode.com/problems/jump-game/) |
| 2026-10-29 | [45. Jump Game II](https://leetcode.com/problems/jump-game-ii/)、[274. H-Index](https://leetcode.com/problems/h-index/) |

## 提交习惯

每天一次提交，message 带上日期和题号：

```
2026-09-21: LeetCode 1768 交替合并字符串
```
