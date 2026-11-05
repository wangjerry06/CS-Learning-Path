//reverse words in string
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
    public:
    string reverseWords(string s){
        vector<string> strs;
        istringstream iss(s);
        string w;
        string res;
        while(iss>>w){
            strs.push_back(w);
        }
        reverse(strs.begin(),strs.end());
        for(int i=0;i<(int)strs.size();++i){
            if(i==0)res+=strs[i];
            else res=res+" "+strs[i];
        }
        return res;
    }
};
int main(){
    Solution sol;
    string s;
    getline(cin,s);              //整行读入，保留中间的空格
    cout<<sol.reverseWords(s)<<endl;
    return 0;
}