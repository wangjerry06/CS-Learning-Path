//subarray sum equals k
#include<iostream>
#include<vector>
#include<unordered_map>
class Solution{
    public:
    int subArraySum(std::vector<int> nums,int k){
        std::unordered_map<long long,int> m;
        m[0]=1;
        long long sum=0;
        int ans=0;
        for(int x:nums){
            sum+=x;
            ans+=m[sum-k];
            ++m[sum];
        }
        return ans;
    }
};
int main(){
    std::vector<int> v={1,1,1};
    Solution A;
    std::cout<<A.subArraySum(v,2)<<'\n';
    return 0;
}