//can make arithmetic progression form a sequance
#include<iostream>
#include<vector>
#include<algorithm>

class Solution{
public:
    bool canMakeArithmeticPregressionFormASequance(std::vector<int> arr){
        sort(arr.begin(),arr.end());
        size_t n=arr.size();
        if(n==2)return true;//记住要==
        int d=arr[1]-arr[0];
        for(size_t i=2;i<n;++i){
            if(arr[i]-arr[i-1]!=d)return false;
        }
        return true;
    }
};
int main(){
    using namespace std;
    int a=0;
    vector<int> arr;
    while(cin>>a){//EOF
        arr.push_back(a);
    }
    Solution ans;//要先生成这个类的的对象，然后在这个对象调用这个函数，最后在赋值到res上
    bool res=ans.canMakeArithmeticPregressionFormASequance(arr);//不要忘了这里是bool
    cout<<boolalpha<<res<<'\n';
    return 0;
}