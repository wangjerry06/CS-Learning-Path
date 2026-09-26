//roman to integer
#include<iostream>
#include<string>
#include<unordered_map>//这里用到了哈希表，今天内会学习

class Solution{
public:
    int romanToInt(std::string s){
       std::unordered_map<char,int> val={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
       //哈希表
        int ans=0;
        size_t count=s.size();
        for(size_t i=0;i<count;++i){
            if(i+1<count&&val[s[i]]<val[s[i+1]]){//注意要判断边界
                ans-=val[s[i]];//如果遇到小的在前面，就减掉，后面大的加上就是4，9这种数字
            }
            else{
                ans+=val[s[i]];
            }
        }
        return ans;
    }
};
int main(){
    std::string s="";
    std::cin>>s;
    Solution A;
    int res=A.romanToInt(s);
    std::cout<<res<<'\n';
    return 0;
}