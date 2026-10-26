//rotate array
#include<iostream>
#include<vector>
#include<algorithm>
class Solution{
    public:
    void rotateArray(std::vector<int>& nums,int k){
        int n=(int)nums.size();
        k%=n;
        std::reverse(nums.begin(),nums.end());
        std::reverse(nums.begin(),nums.begin()+k);
        std::reverse(nums.begin()+k,nums.end());
    }
};
int main(){
    std::vector<int> nums={1,2,3,4,5,6,7};
    Solution A;
    A.rotateArray(nums,3);
    for(int n:nums){
        std::cout<<n<<' ';
    }
    std::cout<<'\n';
    return 0;
}