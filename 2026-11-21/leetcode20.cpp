//valid parentheses
#include<iostream>
#include<string>
#include<stack>
using namespace std;
class Solution{
    public:
    bool isValid(string s){
        stack<char> sta;
        for(char c:s){
            if(c=='('||c=='{'||c=='['){
                sta.push(c);
                continue;
            }
            if(!sta.empty()){
                char tar=sta.top();
                if((c==')'&&tar=='(')||(c=='}'&&tar=='{')||(c==']'&&tar=='[')){
                    sta.pop();
                    continue;
                }
                else return false;
            }
            else return false;
        }
        if(sta.empty())return true;
        else return false;
    }
};

int main(){
    string s;
    cin >> s;
    Solution sol;
    cout << (sol.isValid(s) ? "true" : "false") << endl;
    return 0;
}