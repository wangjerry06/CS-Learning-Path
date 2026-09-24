//sign of the product of an array
#include<iostream>
#include<vector>
#include<algorithm>
class Solution{//昨晚刚学的类的知识
public:
    int arraySign(std::vector<int>& nums){
        if(std::count(nums.begin(),nums.end(),0)!=0){//count一定要加std
            return 0;
        }
        int negcount=0;//和上面的count区分，最好写一些别的
        size_t n=nums.size();
        for(size_t i=0;i<n;++i){
            if(nums[i]<0)++negcount;
        }
        if(negcount%2!=0)return -1;
        return 1;
    }
};
int main(){
    using namespace std;//以下方法用来输入的第一个数字是接下来的数字的个数的情况
    /*int x=0;
    int n=0;
    cin>>n;
    vector<int> v(n);
    for(auto&x:v)cin>>x;*///遍历整个v，把x地址和v绑定，输入到x就存到v
    vector<int> v;
    int n;
    while(cin>>n){//要eof
        v.push_back(n);
    }
    Solution a;//先创建这个类
    cout<<a.arraySign(v)<<'\n';//调用类里的函数
}