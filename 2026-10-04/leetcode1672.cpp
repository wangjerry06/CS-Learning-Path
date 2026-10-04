//Richest Customer wealth
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
class Solution1{//解法一，自己写max和accumulate()
    public:
    int countWealth(std::vector<int> account){
        int sum=0;
        for(int x:account){
            sum+=x;
        }
        return sum;
    }
    int maximumWealth(std::vector<std::vector<int>> accounts){
        int maxWealth=0;
        for(std::vector<int> account:accounts){
            int w=countWealth(account);
            maxWealth=(maxWealth>=w)?maxWealth:w;
        }
        return maxWealth;
    }
};
class Solution2{//解法二：利用algorithm的max和numeric的accumulate
    public:
    int maximumWealth(std::vector<std::vector<int>> accounts){
        int maximum=0;
        for(std::vector<int> account:accounts){
            maximum=std::max(maximum,std::accumulate(account.begin(),account.end(),0));
        }
        return maximum;
    }
};
int main(){
    std::vector<std::vector<int>> v={{1,2,3},{2,3,4}};
    Solution1 A;
    std::cout<<A.maximumWealth(v)<<'\n';
    Solution2 B;
    std::cout<<B.maximumWealth(v)<<'\n';
    return 0;
}