//Add Binary
#include<iostream>
#include<string>
#include<algorithm>
class Solution{
    public:
    std::string addBinary(std::string a,std::string b){
        int i=(int)a.size()-1,j=(int)b.size()-1;
        int carry=0;
        std::string ans="";
        while(i>=0||j>=0||carry){
            int x=(i>=0)?(a[i]-'0'):0;
            int y=(j>=0)?(b[j]-'0'):0;
            int s=x+y+carry;

            ans.push_back(char('0'+s%2));
            carry=s/2;
            --i;--j;
        }
        std::reverse(ans.begin(),ans.end());
        return ans;
    }
};
int main(){
    std::string a="1010",b="1011";
    Solution A;
    std::cout<<A.addBinary(a,b)<<'\n';
    return 0;
}