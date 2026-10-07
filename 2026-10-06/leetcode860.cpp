//lemonade change
#include<iostream>
#include<vector>
class Solution{
    public:
    bool lemonadeChange(const std::vector<int>& bills){
        int n5=0,n10=0;
        for(int b:bills){
            if(b==5)++n5;
            else if(b==10){
                if(n5!=0){--n5;++n10;}
                else return false;
            }
            else {
                if(n5!=0&&n10!=0){
                    --n5;--n10;
                }
                else if(n5>=3){
                    n5-=3;
                }
                else return false;
            }
        }
        return true;
    }
};
int main(){
    std::vector<int> v={5,5,5,10,20};
    Solution A;
    std::cout<<std::boolalpha<<A.lemonadeChange(v)<<'\n';
    return 0;
}