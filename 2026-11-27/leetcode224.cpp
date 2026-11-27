//basic calculator
#include<iostream>
#include<string>
#include<stack>
using namespace std;
class Solution{
    stack<string> st;
    int res=0;
    void calculate(){
        int ans=0;
        while(st.top()!="("){
            while(st.top()==")"){
                st.pop();
                calculate();
                st.pop();
                st.push(to_string(res));
            }
            int a=stoi(st.top());
            st.pop();
            if(st.top()=="("){
                res=ans+a;
                return;
            }
            string op=st.top();
            st.pop();
            if(op=="+"){
                ans=ans+a;
            }
            else{
                ans=ans-a;
            }
        }
        res=ans;
    }
    public:
    int calculate(string s){
        st.push("(");
        int i=0,n=(int)s.length();
        while(i<n){
            if(s[i]==' '){
                ++i;
                continue;
            }
            if(s[i]=='('||s[i]==')'||s[i]=='+'||s[i]=='-'){
                st.push(s.substr(i,1));
            }
            else{
                int start=0;
                while(s[i]!='('&&s[i]!=')'&&s[i]!='+'&&s[i]!='-'){
                    ++i;
                }
                string num=s.substr(start,i-start+1);
                st.push(num);
                continue;
            }
            ++i;
        }
        calculate();
        return res;
    }
};