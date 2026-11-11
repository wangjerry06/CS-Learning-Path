//Text Justification
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution{
    public:
    vector<string> fullJustify(vector<string>& words, int maxWidth){
        vector<string> res;
        int n=(int)words.size();
        int i=0;
        while(i<n){
            int start=i;
            int wordLen=0;
            while(i<n&&wordLen+(i-start)+(int)words[i].size()<=maxWidth){
                wordLen+=(int)words[i].size();
                ++i;
            }

            int cnt=i-start;
            int totalSpace=maxWidth-wordLen;
            string s=words[start];
            if(cnt==1){
                s+=string(totalSpace,' ');
            }
            else if(i==n){
                for(int k=start+1;k<i;++k){
                    s+=" ";
                    s+=words[k];
                }
                s+=string(maxWidth-(int)s.size(),' ');
            }
            else{
                int base=totalSpace/(cnt-1);
                int extra=totalSpace%(cnt-1);
                for(int k=start+1;k<i;++k){
                    int gap=k-start-1;
                    int cur=base+(gap<extra?1:0);
                    s+=string(cur,' ');
                    s+=words[k];
                }
            }
            res.push_back(s);
        }
        return res;
    }
};

int main(){
    int n;
    if(!(cin>>n))return 0;
    vector<string> words(n);
    for(int i=0;i<n;++i)cin>>words[i];
    int maxWidth;
    cin>>maxWidth;
    Solution sol;
    vector<string> res=sol.fullJustify(words,maxWidth);
    cout<<"[\n";
    for(int i=0;i<(int)res.size();++i){
        cout<<"  \""<<res[i]<<"\"";
        if(i+1<(int)res.size())cout<<",";
        cout<<"\n";
    }
    cout<<"]\n";
    return 0;
}