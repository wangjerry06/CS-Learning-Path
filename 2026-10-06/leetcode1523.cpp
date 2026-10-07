//count odd numbers on an interval range
#include<iostream>
class Solution{
    public:
    int countOddNumbers(int low,int high){
        /*思路：先计算high～0的奇数个数：(high+1)/2;
        再计算low-1～0奇数个数：(low-1+1)/2==low/2
        最后两者相减就是区间奇数个数
        */
        return (high+1)/2-low/2;
    }
};

int main(){
    int low=3;
    int high=7;
    Solution A;
    std::cout<<A.countOddNumbers(low,high)<<'\n';
    return 0;
}