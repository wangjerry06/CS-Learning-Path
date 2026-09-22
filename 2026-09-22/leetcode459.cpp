//repeated substring pattern
#include <iostream>
#include <string>

bool check(int pos,const std::string& s){//快一点
    size_t count=s.size();
    if(count%pos!=0){
        return false;//先看能不能被整除
    }
    for(int i=0; i<count-pos;++i){
        if(s[i]!=s[i+pos]){return false;}//逐个比较是不是循环这么多个数
    }
    return true;
}
bool repeatedSubstringPattern(std::string s){
    size_t n=s.size();
    for(int i=1;i<=n/2;++i){//只用找一半
        if(s[i]==s[0]&&check(i,s)){//同时成立才是true
            return true;
        }
    }
    return false;
}
int main(){
    using namespace std;
    string s;
    cin>>s;
    bool ans=repeatedSubstringPattern(s);
    cout<<boolalpha<<ans<<'\n';
    return 0;
}