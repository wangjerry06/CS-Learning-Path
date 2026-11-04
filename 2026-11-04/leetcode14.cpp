//longest common prefix
#include<iostream>
#include<string>
#include<vector>
#include<limits>
using namespace std;
string longestCommonPrefix(vector<string>& strs){
    string res="";
    for(int i=0;i<(int)strs[0].size();++i){
        char tar=strs[0][i];
        bool b=true;
        for(string s:strs){
            if(s[i]!=tar)b=false;
        }
        if(b){
            res.push_back(tar);
        }
        else break;
    }
    return res;
}

int main(){
    int n;
    if(!(cin>>n))return 0;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    vector<string> strs(n);
    for(int i=0;i<n;++i){
        getline(cin,strs[i]);
        if(!strs[i].empty()&&strs[i].back()=='\r')strs[i].pop_back();
    }
    cout<<longestCommonPrefix(strs)<<endl;
    return 0;
}