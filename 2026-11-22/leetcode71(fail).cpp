//simplify path
#include<iostream>
#include<string>
#include<deque>
using namespace std;
class Solution{
    public:
    string simplifyPath(string path){
        deque<char> q;
        q.push_back('/');
        for(char c:path){
            char t=q.back();
            if(c=='.'&&t=='.'){
                q.pop_back();
                if(q.back()=='.'){
                    q.push_back('.');
                    q.push_back('.');
                }
                else if(q.back()!='/'){
                    q.pop_back();
                }
            }
            else if((c=='/'&&t=='/')||(c=='.'&&t!='.'))continue;
            else q.push_back(c);
        }
        while(q.back()=='/')q.pop_back();
        string res;
        while(!q.empty()){
            res.push_back(q.front());
            q.pop_front();
        }
        return res;
    }
};