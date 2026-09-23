//move zeros
#include<iostream>
#include<vector>
 void moveZeros(std::vector<int>& nums){
    size_t n=0;//指针（算法）里的
    for(int i=0;i<nums.size();++i){
        if(nums[i]!=0){
            nums[n++]=nums[i];//把非零的放到前面
        }
    }
    for(int i=n;i<nums.size();++i){
        nums[i]=0;//空的补上0
    }
 }
 int main(){
    using namespace std;
    vector<int> v;
    int k;
    while(cin>>k){
        v.push_back(k);//这种输入方式要在回车之后ctrl+D
        //因为while(cin>>k)的退出条件是遇到EOF文本结束符，所以要按一次回车把文本送进缓冲区，然后用文本结束符让cin>>k返回假
    }
    moveZeros(v);
    for(int i=0;i<v.size();++i){
        cout<<v[i]<<' ';
    }
    cout<<'\n';
    return 0;
 }
