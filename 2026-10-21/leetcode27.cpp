//remove element;
#include<iostream>
#include<vector>
#include<utility>
class Solution{
    public:
    int removeElement(std::vector<int>& nums,int val){
        if(nums.empty())return 0;
        int l=0;
        int r=(int)nums.size()-1;
        while(l<r){
            if(nums[r]!=val){
                if(nums[l]==val){
                    std::swap(nums[l],nums[r]);
                    --r;
                }
                ++l;
            }
            else --r;
        }
        int k=(nums[r]==val)?r:r+1;
        return k;
    }
};
int main(){
    std::vector<int> v={3,2,2,3};
    int n=3;
    Solution A;
    std::cout<<A.removeElement(v,n)<<'\n';
    return 0;
}