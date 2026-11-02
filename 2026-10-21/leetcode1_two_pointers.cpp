//two sum
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
int main(){
    int n=0;
    long long tar=0;
    std::cin>>n>>tar;
    std::vector<std::pair<int,int>> values(n);
    for(int i=0;i<n;++i){
        long long v=0;
        std::cin>>v;
        values[i]={v,i};
    }
    std::sort(values.begin(),values.end());
    int l=0;
    int r=n-1;
    long long sum=0;
    while(l<r){
        sum=(long long)values[l].first+(long long)values[r].first;
        if(sum<tar)++l;
        else if(sum>tar) --r;
        else{
            int i=values[l].second;
            int j=values[r].second;
            if(i>j)std::swap(i,j);
            std::cout<<i<<' '<<j<<'\n';
            return 0;
            }
    }
    return 0;
}