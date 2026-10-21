//count inversion pairs
#include<iostream>
#include<vector>
long long ans=0;
std::vector<int> countInversion(std::vector<int>& nums){
    if(nums.size()<=1)return nums;
    auto mid=nums.begin()+nums.size()/2;
    std::vector<int> L(nums.begin(),mid);
    std::vector<int> R(mid,nums.end());
    std::vector<int> Left=countInversion(L);
    std::vector<int> Right=countInversion(R);
    std::vector<int> res;
    int l=0,r=0;
    while(r<(int)Right.size()&&l<(int)Left.size()){
        if(Left[l]<=Right[r]){
            res.push_back(Left[l]);
            ++l;
        }
        else {
            res.push_back(Right[r]);
            ++r;
            ans+=(int)Left.size()-l;
        }
    }
    while(r<(int)Right.size()){
        res.push_back(Right[r]);
        ++r;
    }
    while(l<(int)Left.size()){
        res.push_back(Left[l]);
        ++l;
    }
    return res;
}
int main(){
    int n=0;
    std::cin>>n;
    std::vector<int> nums(n);
    for(int i=0;i<n;++i){
        std::cin>>nums[i];
    }
    nums=countInversion(nums);
    std::cout<<ans<<'\n';
    return 0;
}