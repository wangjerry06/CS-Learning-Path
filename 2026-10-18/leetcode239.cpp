//sliding window maximum
#include<iostream>
#include<vector>
#include<deque>
class Solution{
    public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k){
        std::deque<int> q;
        std::vector<int> res;
        int n=(int)nums.size();
        q.push_back(0);
        for(int i=1;i<n;++i){
            while(q.front()<i-k+1)q.pop_front();
            while(!q.empty()&&nums[i]>nums[q.back()])q.pop_back();
            q.push_back(i);
            if(i>=k-1)res.push_back(nums[q.front()]);
        }
        return res;
    }
};
int main(){
    std::vector<int> v={1,3,-1,-3,5,3,6,7};
    Solution A;
    std::vector<int> ans=A.maxSlidingWindow(v,3);
    for(int x:ans){
        std::cout<<x<<' ';
    }
    std::cout<<'\n';
    return 0;
}