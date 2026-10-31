//product of array except self
#include<iostream>
#include<vector>

std::vector<int> productExceptSelf(std::vector<int>& nums){
    int n=(int)nums.size();
    // 先数 0：有符号溢出只可能出现在「至少两个 0」时（此时答案必然全 0，
    // 否则非零前缀乘积就是答案的因子、题面保证它落在 int 内）
    int zeros=0,zeroPos=-1;
    for(int i=0;i<n;++i){
        if(nums[i]==0){
            ++zeros;
            zeroPos=i;
        }
    }
    if(zeros>=2){
        return std::vector<int>(n,0);
    }
    if(zeros==1){
        // 只有一个 0：只有 zeroPos 位置是非零元素之积，其余全为 0
        std::vector<int> res(n,0);
        long long p=1;
        for(int i=0;i<n;++i){
            if(i!=zeroPos){
                p*=nums[i];
            }
        }
        res[zeroPos]=(int)p;
        return res;
    }
    // 无 0：前缀/后缀乘积都是答案的因子，不会溢出 int
    std::vector<int> res(n,1);
    for(int i=1;i<n;++i){
        res[i]=res[i-1]*nums[i-1];
    }
    long long right=1;
    for(int i=n-1;i>=0;--i){
        res[i]=(int)(res[i]*right);
        right*=nums[i];
    }
    return res;
}

int main(){
    std::vector<int> nums;
    int x=0;
    while(std::cin>>x){
        nums.push_back(x);
    }
    if(nums.empty()){
        return 0;
    }
    std::vector<int> res=productExceptSelf(nums);
    for(int r:res){
        std::cout<<r<<' ';
    }
    std::cout<<'\n';
    return 0;
}
