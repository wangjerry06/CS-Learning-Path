//best time to buy and sell stock
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
class Solution{
    public:
    int maxProfit(std::vector<int>& prices){
        int pmin=prices[0];
        int best=INT_MIN;
        for(int p:prices){
            if(p<=pmin)pmin=p;
            else best=std::max(best,p-pmin);
        }
        return best;
    }
};
int main(){
    std::vector<int> prices={7,1,5,3,6,4};
    Solution A;
    std::cout<<A.maxProfit(prices)<<'\n';
    return 0;
}