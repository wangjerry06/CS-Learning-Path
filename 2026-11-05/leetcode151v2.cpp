//reverse words in string双指针版
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution{
    public:
    string reverseWords(string s){
        int n=(int)s.size();
        int i=0,k=0;
        //除去开头的所有空格
        while(i<n){
            while(i<n&&s[i]==' ')++i;
            if(i==n)break;
            if(k!=0)s[k++]=' ';
            while(i<n&&s[i]!=' '){
                s[k++]=s[i++];
            }
        }
        s.resize(k);

        reverse(s.begin(),s.end());
        int j=0;
        while(j<k){
            int end=j;
            while(end<k&&s[end]!=' '){
                ++end;
            }
            reverse(s.begin()+j,s.begin()+end);
            j=end+1;
        }
        return s;
    }
};
int main(){
    Solution sol;
    string s;
    getline(cin,s);              //整行读入，保留中间的空格
    cout<<sol.reverseWords(s)<<endl;
    return 0;
}