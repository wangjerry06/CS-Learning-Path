//minimum window substring
#include<iostream>
#include<string>
#include<unordered_map>
#include<climits>
using namespace std;
class Solution{
    public:
    string minWindow(string s,string t){
        int m=(int)s.size();
        int n=(int)t.size();
        if(n>m)return "";

        unordered_map<char,int> tar;
        for(int i=0;i<n;++i){
            tar[t[i]]++;
        }
        int kinds=(int)tar.size();

        unordered_map<char,int> window;
        int cnt=0;
        int bestL=0;
        int bestLen=INT_MAX;
        int l=0;
        for(int r=0;r<m;++r){
            window[s[r]]++;
            if(window[s[r]]==tar[s[r]]){
                cnt++;
            }
            while(cnt==kinds){
                if(r-l+1<bestLen){
                    bestLen=r-l+1;
                    bestL=l;
                }
                if(window[s[l]]==tar[s[l]]){
                    cnt--;
                }
                window[s[l++]]--;
            }
        }
        if(bestLen==INT_MAX)return "";
        return s.substr(bestL,bestLen);
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s,t;
    if(!(cin>>s>>t))return 0;

    Solution sol;
    cout<<sol.minWindow(s,t)<<'\n';
    return 0;
}