//Multiply String
#include<iostream>
#include<string>
#include<algorithm>
class Solution{
    public:
    std::string multiplyString(std::string num1,std::string num2){
        int n1=(int)num1.size(),n2=(int)num2.size();
        std::string ans(n1+n2,'0');
        for(int i=n1-1;i>=0;--i){
            int a=num1[i]-'0';
            for(int j=n2-1;j>=0;--j){
                int x=n1-i-1,y=n2-j-1;
                int b=num2[j]-'0';
                int sum=a*b+ans[x+y]-'0';
                ans[x+y]=char('0'+sum%10);
                ans[x+y+1]=char('0'+(sum/10+ans[x+y+1]-'0'));
            }
        }
        std::reverse(ans.begin(),ans.end());
        while(ans.size()>1&&ans[0]=='0'){
            ans.erase(0,1);
        }
        return ans;
    }
};
int main(){
    std::string a{'0'};
    std::string b="99";
    std::string c="99";
    std::string d="2";
    std::string e="3";
    Solution A;
    std::cout<<A.multiplyString(a,b)<<'\n';
    std::cout<<A.multiplyString(a,c)<<'\n';
    std::cout<<A.multiplyString(b,c)<<'\n';
    std::cout<<A.multiplyString(d,e)<<'\n';
    return 0;
}