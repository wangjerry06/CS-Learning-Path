//range sum query-immutable
#include<iostream>
#include<vector>
class NumArray{
    std::vector<int> pre;
    public:
    NumArray(const std::vector<int>& nums):pre(nums.size()+1,0){
        for(int i=0;i<(int)nums.size();++i){
            pre[i+1]=pre[i]+nums[i];
        }
    }
    int sumRange(int left,int right){
        int res=pre[right+1]-pre[left];
        return res;
    }
};
int main(){
    std::vector<int> nums={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    NumArray A(nums);
    int ans=A.sumRange(3,7);
    std::cout<<ans<<'\n';
    return 0;
}