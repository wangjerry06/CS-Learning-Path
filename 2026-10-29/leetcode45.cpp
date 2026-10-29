//Jump Game II
#include<iostream>
#include<vector>
#include<algorithm>
int jump(std::vector<int>& nums){
    int n=(int)nums.size()-1;
    int curEnd=0,farestEnd=0,sum=0;
    for(int i=0;i<n;++i){
        farestEnd=std::max(farestEnd,i+nums[i]);
        if(i==curEnd){
            ++sum;
            curEnd=farestEnd;
        }
    }
    return sum;
}
int main(){
    int v=0;
    std::vector<int> nums;
    while(std::cin>>v){
        nums.push_back(v);
    }
    std::cout<<jump(nums)<<'\n';
    return 0;
}