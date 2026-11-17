//word pattern
#include<iostream>
#include<string>
#include<unordered_map>
#include<sstream>
#include<vector>
#include<limits>
using namespace std;
class Solution{
    public:
    bool wordPattern(string pattern,string s){
        unordered_map<char,string> ptos;
        unordered_map<string,char> stop;
        vector<string> words;
        istringstream iss(s);
        string tok;
        while(iss>>tok){
            words.push_back(tok);
        }
        if(words.size()!=pattern.size())return false;
        for(int i=0;i<(int)words.size();++i){
            auto it=ptos.find(pattern[i]);
            auto au=stop.find(words[i]);
            if(it==ptos.end())ptos[pattern[i]]=words[i];
            else{
                if(it->second!=words[i])return false;
            }
            if(au==stop.end())stop[words[i]]=pattern[i];
            else{
                if(au->second!=pattern[i])return false;
            }
        }
        return true;
    }
};

int main(){
    string pattern, s;
    cin >> pattern;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, s);
    if(!s.empty() && s[0] == ' ') s.erase(0, 1);

    Solution sol;
    cout << boolalpha << sol.wordPattern(pattern, s) << endl;
    return 0;
}