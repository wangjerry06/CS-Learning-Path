// LeetCode 976. 三角形的最大周长 —— 修正版
// 关键修正：先排序，再从最大的三条边开始往左扫描
// 时间复杂度：O(n log n)（排序主导）  空间复杂度：O(1)（忽略排序自身）
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int largestPerimeter(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());                 // ① 排序：这是原解缺失的关键一步
        for (int i = static_cast<int>(nums.size()) - 1; i >= 2; --i) {   // ② 用 int，避免 size_t 下溢
            if (nums[i] < nums[i - 1] + nums[i - 2])          // 三边关系：较短两边之和 > 最长边
                return nums[i] + nums[i - 1] + nums[i - 2];
        }
        return 0;                                             // 找不到任何三角形
    }
};

int main() {
    int x;
    std::vector<int> v;
    while (std::cin >> x) v.push_back(x);
    Solution A;
    std::cout << A.largestPerimeter(v) << '\n';
    return 0;
}
