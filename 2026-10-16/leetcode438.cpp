//find all anagrams in string
#include<iostream>
#include<string>
#include<vector>
class Solution{
    public:
    std::vector<int> findAnagrams(std::string s, std::string p){
        std::vector<int> ans;
        int ns=(int)s.size();
        int np=(int)p.size();
        if(ns<np||p.empty())return ans;

        std::array<int,26> need{},win{};
        for(char cha:p){
            ++need[cha-'a'];
        }//创建计数表

        int diff=0;
        for(int i=0;i<26;++i){
            if(win[i]!=need[i])++diff;
        }//计数器做bool，如果diff=0就代表一样，如果!=0就是有差别

        for(int r=0;r<ns;++r){
            int ch=s[r]-'a';
            if(win[ch]==need[ch])++diff;
            ++win[ch];
            if(win[ch]==need[ch])--diff;
            //右端进来
            
            if(r>=np){
                int c=s[r-np]-'a';
                if(win[c]==need[c])++diff;
                --win[c];
                if(win[c]==need[c])--diff;
            }
            //左端出
            
            if(r>=np-1&&diff==0)ans.push_back(r-np+1);
        }
        return ans;
    }
};
int main(){
    std::string s="cbaebabacd";
    std::string p="abc";
    Solution A;
    std::vector<int> res=A.findAnagrams(s,p);
    for(int s:res){
        std::cout<<s<<' '<<'\n';
    }
    return 0;
}