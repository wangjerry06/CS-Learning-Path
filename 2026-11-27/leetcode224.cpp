//basic calculator
#include<iostream>
#include<string>
#include<stack>
#include<climits>
using namespace std;
class Solution{
    stack<string> st;
    long long res=0;
    void calculate(){
        long long ans=0;
        while(st.top()!="("){
            while(st.top()==")"){
                st.pop();
                calculate();
                st.pop();
                st.push(to_string(res));
            }
            long long a=stoll(st.top());
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
                int start=i;
                while(i<n&&s[i]!='('&&s[i]!=')'&&s[i]!='+'&&s[i]!='-'){
                    ++i;
                }
                string num=s.substr(start,i-start);
                st.push(num);
                continue;
            }
            ++i;
        }
        calculate();
        return (int)res;
    }
};

int main(){
    // 三个官方样例 + 几个专门抓坑的用例（连续减法、多位数、空格、INT_MIN、一元负号）
    string inputs[] = {
        "1 + 1",
        " 2-1 + 2 ",
        "(1+(4+5+2)-3)+(6+8)",
        "10-4-3",
        "1+23",
        "( 3 + 4 ) - ( 2 - 8 )",
        "-2147483648",
        "0-2147483648",
        "-(2+3)"
    };
    int expects[] = {2, 3, 23, 3, 24, 13, INT_MIN, INT_MIN, -5};
    int count = 9;
    for(int i=0;i<count;i++){
        Solution sol;
        int got=sol.calculate(inputs[i]);
        cout<<"输入: ["<<inputs[i]<<"]  期望 "<<expects[i]<<"  实得 "<<got;
        if(got==expects[i]){
            cout<<"   过"<<endl;
        }
        else{
            cout<<"   挂"<<endl;
        }
    }
    return 0;
}