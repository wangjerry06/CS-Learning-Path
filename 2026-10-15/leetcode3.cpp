//longest substring without repeating characters
#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;
class Solution{
    public:
    int lengthOfLongestSubstring(string s){
        unordered_set<int> sub;
        int l=0,ans=0;
        for(int r=0;r<(int)s.size();++r){
            while(sub.count(s[r])){
                sub.erase(s[l]);
                ++l;
            }
            sub.insert(s[r]);
            ans=(ans>r-l+1)?ans:r-l+1;
        }
        return ans;
    }
};
int main(){
    string s="abcabcbb";
    Solution A;
    cout<<A.lengthOfLongestSubstring(s)<<'\n';
    return 0;
}