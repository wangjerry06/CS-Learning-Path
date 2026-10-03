//Baseball Game
#include<iostream>
#include<vector>
#include<string>
class Solution{
    public:
    int calPoints(std::vector<std::string> operation){
        std::vector<int> scores;
        for(const std::string& op:operation){
            if(op=="+"){
                size_t n=scores.size();
                scores.push_back(scores[n-1]+scores[n-2]);
            }
            else if(op=="D"){
                scores.push_back(2*scores.back());
            }
            else if(op=="C"){
                scores.pop_back();
            }
            else{
                scores.push_back(std::stoi(op));
            }
        }
        int ans=0;
        for(int x:scores){ans+=x;}
        return ans;
    }
};
int main(){
    std::vector<std::string> operation={"5","2","C","D","+"};
    Solution A;
    std::cout<<A.calPoints(operation)<<'\n';
    return 0;
}