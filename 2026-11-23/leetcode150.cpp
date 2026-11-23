//evaluate reverse polish notation
#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string s:tokens){
            if(s!="*"&&s!="+"&&s!="-"&&s!="/"){
                st.push(stoi(s));
                continue;
            }
            int b=st.top();
            st.pop();
            int a=st.top();
            st.pop();
            if(s=="*"){
                st.push(a*b);
            }
            else if(s=="+"){
                st.push(a+b);
            }
            else if(s=="-"){
                st.push(a-b);
            }
            else{
                st.push(a/b);
            }
        }
        return st.top();
    }
};

int main(){
    int n;
    cin>>n;
    vector<string> tokens(n);
    for(int i=0;i<n;i++){
        cin>>tokens[i];
    }
    Solution sol;
    cout<<sol.evalRPN(tokens)<<endl;
    return 0;
}