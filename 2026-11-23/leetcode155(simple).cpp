//min stack
#include<iostream>
#include<climits>
#include<algorithm>
#include<stack>
#include<string>
using namespace std;
class MinStack{
    stack<int> st;
    stack<int> minSt;
    public:
    MinStack(){
        minSt.push(INT_MAX);
    }

    void push(int value){
        st.push(value);
        minSt.push(min(minSt.top(),value));
    }

    void pop(){
        st.pop();
        minSt.pop();
    }

    int top(){
        return st.top();
    }

    int getMin(){
        return minSt.top();
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if(!(cin >> n)) return 0;

    MinStack obj;
    string op;
    for(int i = 0; i < n; ++i){
        cin >> op;
        if(op == "MinStack"){
            continue;               // 构造标记，对象已创建
        }
        else if(op == "push"){
            int val;
            cin >> val;
            obj.push(val);
        }
        else if(op == "pop"){
            obj.pop();
        }
        else if(op == "top"){
            cout << obj.top() << '\n';
        }
        else if(op == "getMin"){
            cout << obj.getMin() << '\n';
        }
    }
    return 0;
}