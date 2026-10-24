//insert into a binary search tree —— 修正版（1-based 哨兵 + 迭代下降）
#include<iostream>
#include<vector>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n=0,val=0;
    if(!(std::cin>>n>>val)) return 0;

    // a[0] 当哨兵不用，这样「节点编号 == 数组下标」，彻底躲开 off-by-one
    std::vector<std::vector<int>> a;
    a.push_back(std::vector<int>{0,0,0});
    for(int i=0;i<n;++i){
        int v=0,l=0,r=0;
        std::cin>>v>>l>>r;
        a.push_back(std::vector<int>{v,l,r});
    }

    if(n==0){
        std::cout<<1<<'\n'<<val<<" 0 0\n";
        return 0;
    }

    // 从根出发，只看「下一步要去的那个孩子」是否为空
    int cur=1;
    while(true){
        if(val<a[cur][0]){
            if(a[cur][1]==0){ a[cur][1]=(int)a.size(); break; }
            cur=a[cur][1];
        }else{
            if(a[cur][2]==0){ a[cur][2]=(int)a.size(); break; }
            cur=a[cur][2];
        }
    }
    a.push_back(std::vector<int>{val,0,0});   // 新节点编号 = 压入前的大小

    std::cout<<(int)a.size()-1<<'\n';
    for(size_t i=1;i<a.size();++i){
        std::cout<<a[i][0]<<' '<<a[i][1]<<' '<<a[i][2]<<'\n';
    }
    return 0;
}
