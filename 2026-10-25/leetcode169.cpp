//majority element
#include<iostream>
#include<vector>
class Solution{
    public:
    int majorityElement(std::vector<int> nums){
        int count=0;
        int candidate=nums[0];
        for(int n:nums){
            if(n==candidate)++count;
            else if(n!=candidate&&count==0)candidate=n;
            else --count;
        }
        return candidate;
    }
};
int main(){
    std::vector<int> nums={3,2,3};
    Solution A;
    std::cout<<A.majorityElement(nums)<<'\n';
    return 0;
}