//Length of Last Word
#include<iostream>
#include<string>
#include<sstream>//istringstream在里边，记得写
class Solution {
public:
    int lengthOfLastWord(std::string s) {
        std::istringstream iss(s);//跳过空格读取，空格为分界
        std::string word="";
        std::string last="";
        while(iss>>word){
            last=word;
        }
        return last.size();
    }
};
int main(){
    std::string input;
    Solution solution;
    std::getline(std::cin,input);//这样才是读一整行，包括空格
    std::cout<<solution.lengthOfLastWord(input)<<'\n';
    return 0;
}