//insert into a binary search tree
#include<iostream>
#include<vector>
int n=0;
void inserter(std::vector<std::vector<int>>& a,int val,int start){
    if(val<a[start-1][0]){
        if(a[start-1][1]==0){
            a[start-1][1]=n+1;
            a.push_back({val,0,0});
        }
        else {
            start=a[start-1][1];
            inserter(a,val,start);
        }
    }
    else{
        if(a[start-1][2]==0){
            a[start-1][2]=n+1;
            a.push_back({val,0,0});
        }
        else{
            start=a[start-1][2];
            inserter(a,val,start);
        }
    }
}
int main(){
    n=0;
    int val=0;
    std::cin>>n>>val;
    if(n==0){
        std::cout<<1<<'\n'<<val<<' '<<0<<' '<<0<<'\n';
        return 0;
    }
    std::vector<std::vector<int>> res;
    for(int i=0;i<n;++i){
        std::vector<int> a(3);
        for(int j=0;j<3;++j){
            std::cin>>a[j];
        }
        res.push_back(a);
    }
    inserter(res,val,1);
    std::cout<<n+1<<'\n';
    for(int i=0;i<n+1;++i){
        std::cout<<res[i][0]<<' '<<res[i][1]<<' '<<res[i][2]<<'\n';
    }
    return 0;
}
