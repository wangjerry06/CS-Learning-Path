//Spiral Matrix
#include<iostream>
#include<vector>
class Solution{
    public:
    std::vector<int> spiralOrder(const std::vector<std::vector<int>>& matrix) {
        int up=0;
        int left=0;
        int right=matrix[0].size()-1;
        int lower=matrix.size()-1;
        std::vector<int> ans;
        ans.reserve(matrix.size()*matrix[0].size());
        while(up<=lower&&left<=right){
            //向右读取，边界向下移动    为什么这里不用判断，因为在while里已经判断过了
            for(int i=left;i<=right;++i){
                ans.push_back(matrix[up][i]);
            }
            ++up;
            //向下读取，边界向左移动    为什么这里不用判断，如果up>lower，循环直接终止
            for(int i=up;i<=lower;++i){
                ans.push_back(matrix[i][right]);
            }
            --right;
            //向左读取，边界向上移动
            if(up<=lower){
                for(int i=right;i>=left;--i){
                    ans.push_back(matrix[lower][i]);
                }
                --lower;
            }
            //向上读取，边界向左移动
            if(left<=right){
                for(int i=lower;i>=up;--i){
                    ans.push_back(matrix[i][left]);
                }
                ++left;
            }
        }
        return ans;
    }
};
int main(){
    std::vector<std::vector<int>> v={{1,2,3},{4,5,6},{7,8,9}};
    Solution A;
    std::vector<int> res=A.spiralOrder(v);
    for(int x:res){
        std::cout<<x<<' ';
    }
    std::cout<<'\n';
    return 0;
}