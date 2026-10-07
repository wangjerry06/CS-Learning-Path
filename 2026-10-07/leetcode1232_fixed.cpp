// LeetCode 1232. 缀点成线（Check If It Is a Straight Line）—— 修正版
// 关键修正：用「交叉相乘」判断共线，彻底避开除法（既无除零风险，也无整数截断）
//
// 共线判定原理：三点 P0(x0,y0)、P1(x1,y1)、Pi(xi,yi) 共线
//   ⇔ 斜率相等 ⇔ (y1-y0)/(x1-x0) == (yi-y0)/(xi-x0)
//   ⇔ 交叉相乘：(y1-y0)*(xi-x0) == (yi-y0)*(x1-x0)   ← 无除法，竖直/水平通吃
//
// 时间复杂度 O(n)，空间复杂度 O(1)
#include <vector>
using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x0 = coordinates[0][0], y0 = coordinates[0][1];
        int dx = coordinates[1][0] - x0, dy = coordinates[1][1] - y0;   // 基准方向向量
        for (int i = 2; i < (int)coordinates.size(); ++i) {
            int x = coordinates[i][0] - x0, y = coordinates[i][1] - y0;
            // 叉积为 0 ⇔ 共线：(x1-x0)*(yi-y0) == (y1-y0)*(xi-x0)
            if ((long long)dx * y != (long long)dy * x) return false;
        }
        return true;
    }
};
