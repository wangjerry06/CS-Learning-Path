//H-index
#include<iostream>
#include<vector>
#include<algorithm>
int hIndex(std::vector<int> citations){
    std::sort(citations.begin(),citations.end());
    int h=0;
    int n=(int)citations.size();
    for(int i=n-1;i>=0;--i){
        int num=n-i;
        if(citations[i]>=num)h=num;
        else break;
    }
    return h;
}
int main(){
    std::vector<int> citations;
    int times=0;
    while(std::cin>>times){
        citations.push_back(times);
    }
    std::cout<<hIndex(citations)<<'\n';
    return 0;
}