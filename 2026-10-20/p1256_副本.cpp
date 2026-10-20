#include<string>
#include<iostream>
#include<stack>
bool validParenthese(std::string inp){
    int n=(int)inp.size();
    if(n==0||n%2!=0)return false;
    std::stack<char> a;
    for(char c:inp){
        if(c=='('||c=='['||c=='{')a.push(c);
        else{
            if(a.empty())return false;
            char tp=a.top();
            if((c==')'&&tp!='(')||(c==']'&&tp!='[')||(c=='}'&&tp!='{')){
                return false;
            }
            a.pop();
        }
    }
    if(a.empty())return true;
    return false;
}
int main(){
    std::string inp="";
    std::cin>>inp;
    std::cout<<std::boolalpha<<validParenthese(inp)<<'\n';
    return 0;
}