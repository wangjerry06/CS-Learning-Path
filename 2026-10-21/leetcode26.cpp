//remove duplicates from sorted array
#include<iostream>
#include<vector>
#include<utility>
int removeDuplicates(std::vector<int>& nums){
    int l=0;
    int n=(int)nums.size();
    for(int r=0;r<n;++r){
        if(nums[r]!=nums[l]){
            std::swap(nums[++l],nums[r]);
        }
    }
    return l+1;
}
int main(){
    std::vector<int> v={1,2,2,3,3,3,4,4,4,4};
    std::cout<<removeDuplicates(v);
    return 0;

}