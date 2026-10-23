//remove duplicates from sorted array II
#include<iostream>
#include<vector>
class Solution{
    public:
    int removeDuplicates(std::vector<int>& nums){
        int k=0;
        for(int i=0;i<(int)nums.size();++i){
            if(k<2||nums[k-2]!=nums[i]){
                nums[k++]=nums[i];
            }
        }
        return k;
    }
};
int main(){
    std::vector<int> v={1,1,1,1,1};
    Solution A;
    std::cout<<A.removeDuplicates(v)<<'\n';
    return 0;
}