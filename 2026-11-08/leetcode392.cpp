//is Subsequence
#include<iostream>
#include<string>
using namespace std;
bool isSubsequence(string s,string t){
    int sn=(int)s.size(),tn=(int)t.size();
    int sp=0,tp=0;
    while(sp<sn&&tp<tn){
        if(s[sp]==t[tp])++sp;
        ++tp;
    }
    return sp==sn;
}
int main(){
    string s,t;
    getline(cin,s);
    getline(cin,t);
    cout<<(isSubsequence(s,t)?"true":"false")<<endl;
    return 0;
}