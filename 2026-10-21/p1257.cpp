//evaluate reverse polish number
#include<iostream>
#include<string>
#include<stack>
int main(){
    int n=0;
    std::cin>>n;
    std::stack<long long> st;
    for(int i=0;i<n;++i){
        std::string tok="";
        std::cin>>tok;
        bool isOp=(tok.size()==1)&&(tok[0]=='+'||tok[0]=='-'||tok[0]=='*'||tok[0]=='/');
        if(!isOp){
            st.push(std::stoll(tok));
        }
        else {
            int b=st.top();
            st.pop();
            int a=st.top();
            st.pop();
            if(tok=="+")st.push(a+b);
            else if(tok=="-")st.push(a-b);
            else if(tok=="*")st.push(a*b);
            else st.push(a/b);
        }
    }
    std::cout<<st.top()<<'\n';
    return 0;
}