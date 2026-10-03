//To Lower case
#include<iostream>
#include<vector>
#include<string>
class Solution{
    public:
    std::string ThelowerCase(std::string s){
        for(char& c:s){
            if(c>='A'&&c<='Z'){
                c=c+'a'-'A';
            }
        }
        return s;
    }
};
int main(){
    std::string s={};
    std::cin>>s;
    Solution A;
    std::cout<<A.ThelowerCase(s)<<'\n';
}