//Robot Bounded in Circle
#include<iostream>
#include<utility>
#include<string>
class Solution{
    public:
    void go(std::pair<int,int>& pos,const int& dir){
        if(dir%4==0)pos.second+=1;
        else if((dir-1)%4==0)pos.first-=1;
        else if((dir-2)%4==0)pos.second-=1;
        else pos.first+=1;
    }
    bool check(std::string instruction,int& dir,std::pair<int,int>& pos){
        for(char& s:instruction){
            if(s=='L')dir+=1;
            else if(s=='R')dir-=1;
            else if(s=='G')go(pos,dir);
        }
        if(pos.first==0&&pos.second==0)return true;
        return false;
    }
    bool isRobotBounded(std::string instruction){
        int dir=0;
        std::pair<int,int> pos{0,0};
        if(!check(instruction,dir,pos)){
            for(int i=0;i<4;++i){
                if(check(instruction,dir,pos))return true;
            }
            return false;
        }
        return true;
    }
};
int main(){
    std::string instruction="GL";
    Solution A;
    std::cout<<std::boolalpha<<A.isRobotBounded(instruction)<<'\n';
    return 0;
}