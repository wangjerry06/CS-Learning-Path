//range sum query - mutable
#include<iostream>
#include<vector>
#include<string>
#include<cctype>
using namespace std;
class NumArray{
    vector<int> segmentTree;
    int n;

    void build(int node,int l,int r,vector<int>& nums){
        if(l==r){
            segmentTree[node]=nums[l];
            return;
        }
        int m=l+(r-l)/2;
        build(node*2,l,m,nums);
        build(node*2+1,m+1,r,nums);
        segmentTree[node]=segmentTree[node*2]+segmentTree[node*2+1];
    }
    
    void change(int index,int val,int node,int l,int r){
        if(l==r){
            segmentTree[node]=val;
            return;
        }
        int m=l+(r-l)/2;
        if(index<=m){
            change(index,val,node*2,l,m);
        }
        else {
            change(index,val,node*2+1,m+1,r);
        }
        segmentTree[node]=segmentTree[node*2]+segmentTree[node*2+1];
    }

    int range(int left,int right,int node,int l,int r){
        if(left==l&&right==r){
            return segmentTree[node];
        }
        int m=l+(r-l)/2;
        if(right<=m){
            return range(left,right,node*2,l,m);
        }
        else if(left>m){
            return range(left,right,node*2+1,m+1,r);
        }
        else{
            return range(left,m,node*2,l,m)+range(m+1,right,node*2+1,m+1,r);
        }
    }

    public:
    NumArray(vector<int>nums){
        n=(int)nums.size();
        segmentTree.assign(n*4,0);
        build(1,0,n-1,nums);
    }
    void update(int index,int val){
        change(index,val,1,0,n-1);
    }
    int sumRange(int left,int right){
        return range(left,right,1,0,n-1);
    }
};

/*
输入格式：
  第一行：nums.length（记为 n）
  第二行：n 个整数 nums[0..n-1]
  第三行：操作次数 q
  接下来 q 行，每行是下面两种之一（命令不区分大小写，也可用 u / s 简写）：
      update index val
      sumRange left right
  每次 sumRange 立即输出一行结果；若省略 q，则一直读到文件末尾。

样例输入：
  3
  1 3 5
  3
  sumRange 0 2
  update 1 2
  sumRange 0 2
样例输出：
  9
  8
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if(!(cin>>n)||n<=0) return 0;
    vector<int> nums(n);
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }

    NumArray obj(nums);

    int q=-1;                       // q<0 表示没有给出操作次数，读到 EOF 为止
    if(!(cin>>q)){
        cin.clear();                // 关键：清掉 failbit，否则后面所有读取都会失败
        q=-1;
    }

    while(q!=0){
        string op;
        if(!(cin>>op)) break;
        for(char& c:op) c=(char)tolower((unsigned char)c);

        if(op=="update"||op=="u"||op=="change"){
            int index,val;
            if(!(cin>>index>>val)) break;
            obj.update(index,val);
        }
        else if(op=="sumrange"||op=="sum"||op=="range"||op=="s"||op=="r"){
            int left,right;
            if(!(cin>>left>>right)) break;
            cout<<obj.sumRange(left,right)<<'\n';
        }
        else{
            // 无法识别的命令：跳过本行，避免读错参数
            string rest;
            getline(cin,rest);
        }

        if(q>0) --q;
    }
    return 0;
}