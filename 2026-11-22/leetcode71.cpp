//simplify path
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution{
    public:
    string simplifyPath(string path){
        vector<string> st;
        int i=0;
        int n=(int)path.size();
        while(i<n){
            if(path[i]=='/'){
                ++i;
                continue;
            }
            int j=i;
            while(j<n&&path[j]!='/'){
                ++j;
            }
            string tok=path.substr(i,j-i);
            if(tok=="."){
                // 当前目录，忽略
            }
            else if(tok==".."){
                if(!st.empty())st.pop_back();
            }
            else st.push_back(tok);
            i=j;
        }
        if(st.empty())return "/";
        string res;
        for(size_t i=0;i<st.size();++i){
            res+="/";
            res+=st[i];
        }
        return res;
    }
};

int main(){
    string path;
    // 输入不含空格，直接读入整行路径
    cin>>path;
    Solution sol;
    cout<<sol.simplifyPath(path)<<endl;
    return 0;
}