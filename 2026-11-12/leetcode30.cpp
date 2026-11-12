//substring with concatenation of all words
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
class Solution{
    public:
    vector<int> findSubstring(string s,vector<string>& word){
        vector<int> res;
        if(s.empty()||word.empty())return res;
        int m=(int)word.size();
        int w=(int)word[0].size();
        int n=(int)s.size();
        int total=m*w;
        if(n<total)return res;

        unordered_map<string,int>need;
        for(int i=0;i<m;++i){
            need[word[i]]++;
        }

        for(int offset=0;offset<w;++offset){
            unordered_map<string,int> window;
            int cnt=0;
            int left=offset;

            for(int right=offset;right+w<=n;right+=w){
                string in=s.substr(right,w);
                window[in]++;
                if(need.count(in)&&window[in]<=need[in])cnt++;
                while(right+w-left>total){
                    string out=s.substr(left,w);
                    if(need.count(out)&&window[out]<=need[out])cnt--;
                    window[out]--;
                    left+=w;
                }
                if(cnt==m)res.push_back(left);
            }
        }
        return res;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if(!(cin>>s))return 0;

    int m;
    cin>>m;
    vector<string> words(m);
    for(int i=0;i<m;++i){
        cin>>words[i];
    }

    Solution sol;
    vector<int> ans=sol.findSubstring(s,words);

    cout<<ans.size()<<"\n";
    for(int i=0;i<(int)ans.size();++i){
        if(i)cout<<' ';
        cout<<ans[i];
    }
    cout<<"\n";
    return 0;
}
