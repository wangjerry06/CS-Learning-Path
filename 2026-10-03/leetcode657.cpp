//Robot return to origin
#include<iostream>
#include<utility>
#include<string>
class Solution{
    public:
    bool judgeCircle(std::string moves){
        std::pair<int,int> loc{0,0};//用pair来表示坐标
        for(char& x:moves){
            if(x=='U')loc.second+=1;
            else if(x=='D')loc.second-=1;
            else if(x=='L')loc.first-=1;
            else if(x=='R')loc.first+=1;
            else return false;
        }
        if(loc.first==0&&loc.second==0)return true;
        else return false;
    }
};
int main(){
    std::string s="";
    std::cin>>s;
    Solution A;
    std::cout<<std::boolalpha<<A.judgeCircle(s)<<'\n';
    return 0;
}