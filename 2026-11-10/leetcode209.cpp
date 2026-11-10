//minimum size subarray sum
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
class Solution{
    vector<int> leftSum;
    int countCross(int target,vector<int>& nums,int l,int r,int m){
        int s=0;
        for(int i=m;i>=l;--i){
            s+=nums[i];
            leftSum[i]=s;
        }
        int bestCross=INT_MAX;
        int i=l;
        int rightSum=0;
        for(int j=m+1;j<=r;++j){
            rightSum+=nums[j];
            while(i<=m&&leftSum[i]+rightSum>=target){
                int cur=j-i+1;
                bestCross=min(cur,bestCross);
                ++i;
            }
        }
        return bestCross;
    }
    int countLen(int target,vector<int>& nums,int l,int r){
        if(l==r){
            if(nums[l]>=target)return 1;
            else return INT_MAX;
        }

        int m=l+(r-l)/2;
        int lbest=countLen(target,nums,l,m);
        int rbest=countLen(target,nums,m+1,r);

        int bestCross=countCross(target,nums,l,r,m);
        return min(bestCross,min(lbest,rbest));
    }
    public:
    int minSubArrayLen(int target,vector<int>& nums){
        int n=(int)nums.size();
        if(n==0)return 0;
        leftSum.assign(n,0);
        int res=countLen(target,nums,0,n-1);
        if(res==INT_MAX)return 0;
        return res;
    }
};

// 输入格式：
// 第1行 target
// 第2行 n（数组长度）
// 第3行 n 个整数 nums[i]
// 输出：最短子数组长度，不存在则输出 0
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int target, n;
    if(!(cin>>target)) return 0;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }

    Solution sol;
    cout<<sol.minSubArrayLen(target,nums)<<'\n';
    return 0;
}