//valid palindrome
#include<iostream>
#include<string>
using namespace std;
class Solution{
    public:
    bool normalize(char& c){
        if((c>='A'&&c<='Z')||(c>='a'&&c<='z')||(c>='0'&&c<='9')){
            if(c>='A'&&c<='Z')c=c+'a'-'A';
            return true;
        }
        return false;
    }
    bool isPalindrome(string s){
        int l=0;
        int r=(int)s.size()-1;
        while(l<=r){
            while(l<=r&&!normalize(s[l]))++l;
            while(l<=r&&!normalize(s[r]))--r;
            if(l<=r&&s[r]!=s[l])return false;
            ++l;--r;
        }
        return true;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin,s);
    if(!s.empty()&&s.back()=='\r')s.pop_back();

    Solution sol;
    cout<<(sol.isPalindrome(s)?"true":"false")<<'\n';
    return 0;
}