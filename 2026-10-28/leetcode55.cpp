//jump game
#include<iostream>
#include<vector>
#include<algorithm>
bool jumpGame(std::vector<int>& nums){
    int n=(int)nums.size();
    int best=0;
    for(int i=0;i<n;++i){
        if(nums[i]==0&&i!=n-1&&best<i)return false;
        best=std::max(best,i+nums[i]);
    }
    return true;
}
int main(){
    std::vector<int> nums={3,2,1,0};
    std::cout<<std::boolalpha<<jumpGame(nums)<<'\n';
    return 0;
}