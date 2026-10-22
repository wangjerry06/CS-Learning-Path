//maximum subarray,也是p1260
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

int best=INT_MIN;
int dfs(int i,std::vector<int>& nums){
    if(i==0){
        best=std::max(best,nums[0]);
        return nums[0];
    }
    int prev=dfs(i-1,nums);
    int cur=std::max(prev+nums[i],nums[i]);
    best=std::max(cur,best);
    return cur;
}
int main(){
    int n=0;
    std::cin>>n;
    std::vector<int> nums(n);
    for(int i=0;i<n;++i){
        std::cin>>nums[i];
    }
    int ns=(int)nums.size()-1;
    best=INT_MIN;
    dfs(ns,nums);
    std::cout<<best<<'\n';
    return 0;
}