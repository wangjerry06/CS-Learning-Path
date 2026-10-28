//best time to buy and sell stock II
#include<iostream>
#include<vector>
int maxProfit(std::vector<int>& prices){
    int sum=0;
    int n=(int)prices.size();
    for(int i=1;i<n;++i){
        if(prices[i]-prices[i-1]>0)sum+=prices[i]-prices[i-1];
    }
    return sum;
}
int main(){
    std::vector<int> prises={7,1,5,3,6,4};
    std::cout<<maxProfit(prises)<<'\n';
    return 0;
}