//candy
#include<iostream>
#include<vector>
#include<algorithm>
long long candy(std::vector<int> ratings){
    long long sum=0;
    int n=(int)ratings.size();
    std::vector<int> L(n);
    std::vector<int> R(n);
    for(int l=0;l<n;++l){
        if(l>0&&ratings[l]>ratings[l-1]){
            L[l]=L[l-1]+1;
        }
        else{
            L[l]=1;
        }
    }
    for(int r=n-1;r>=0;--r){
        if(r<n-1&&ratings[r]>ratings[r+1]){
            R[r]=R[r+1]+1;
        }
        else{
            R[r]=1;
        }
    }
    for(int i=0;i<n;++i){
        sum+=std::max(R[i],L[i]);
    }
    return sum;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    if(!(std::cin>>n)) return 0;       // 读到 EOF 就正常退出（方便多组测试）
    std::vector<int> ratings(n);
    for(int i=0;i<n;++i){
        std::cin>>ratings[i];
    }
    std::cout<<candy(ratings)<<'\n';
    return 0;
}