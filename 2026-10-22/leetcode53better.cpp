//分治版
#include<iostream>
#include<vector>
#include<algorithm>
struct Status{
    int lSum;
    int rSum;
    int mSum;
    int iSum;
};
Status pushUp(Status l,Status r){
    int iSum=l.iSum+r.iSum;
    int lSum=std::max(l.lSum,l.iSum+r.lSum);
    int rSum=std::max(r.rSum,r.iSum+l.rSum);
    int mSum=std::max(std::max(l.mSum,r.mSum),l.rSum+r.lSum);
    return {lSum,rSum,mSum,iSum};
}
Status get(std::vector<int>& a,int l,int r){
    if(l==r)return {a[l],a[l],a[l],a[l]};
    int m=l+(r-l)/2;
    Status lSub=get(a,l,m);
    Status rSub=get(a,m+1,r);
    return pushUp(lSub,rSub);
}
int main(){
    int n=0;
    std::cin>>n;
    std::vector<int> nums(n);
    for(int i=0;i<n;++i){
        std::cin>>nums[i];
    }
    Status res=get(nums,0,(int)nums.size()-1);
    std::cout<<res.mSum<<'\n';
    return 0;
}