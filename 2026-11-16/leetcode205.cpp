//Isomorphic Strings
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
class Solution{
    public:
    bool isIsomorphic(string s,string t){
        int n=(int)s.size();
        int m=(int)t.size();
        if(n!=m)return false;
        unordered_map<char,char> mapS2T;
        unordered_map<char,char> mapT2S;
        for(int i=0;i<n;++i){
            auto it=mapS2T.find(s[i]);
            if(it==mapS2T.end()){
                mapS2T[s[i]]=t[i];
            }
            else{
                if(it->second!=t[i])return false;
            }
        }
        for(int i=0;i<m;++i){
            auto it=mapT2S.find(t[i]);
            if(it==mapT2S.end()){
                mapT2S[t[i]]=s[i];
            }
            else{
                if(it->second!=s[i])return false;
            }
        }
        return true;
    }
};
int main(){
    string s,t;
    if(!getline(cin,s))return 0;
    if(!getline(cin,t))return 0;
    // 去掉 Windows 换行可能残留的 '\r'
    if(!s.empty()&&s.back()=='\r')s.pop_back();
    if(!t.empty()&&t.back()=='\r')t.pop_back();
    Solution sol;
    cout<<(sol.isIsomorphic(s,t)?"true":"false")<<endl;
    return 0;
}