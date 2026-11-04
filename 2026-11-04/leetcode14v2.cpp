//最大公共前缀分治版
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<limits>
std::string CommonPrefix(const std::string& lcp,const std::string& rcp){
    int minLength=(int)std::min(lcp.size(),rcp.size());
    std::string res="";
    for(int i=0;i<minLength;++i){
        if(lcp[i]!=rcp[i]){
            break;
        }
        else{
            res.push_back(lcp[i]);
        }
    }
    return res;
}
std::string longestCommonPrefix(const std::vector<std::string>& strs,int start,int end){
    if(start==end)return strs[start];
    else{
        int m=start+(end-start)/2;
        std::string lcp=longestCommonPrefix(strs,start,m);
        std::string rcp=longestCommonPrefix(strs,m+1,end);
        return CommonPrefix(lcp,rcp);
    }
}
std::string longestCommonPrefix(const std::vector<std::string>& strs){
    if(strs.size()==0)return "";
    else return longestCommonPrefix(strs,0,(int)strs.size()-1);
}
int main(){
    using namespace std;
    int n;
    if(!(cin>>n))return 0;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    vector<string> strs(n);
    for(int i=0;i<n;++i){
        getline(cin,strs[i]);
        if(!strs[i].empty()&&strs[i].back()=='\r')strs[i].pop_back();
    }
    cout<<longestCommonPrefix(strs)<<endl;
    return 0;
}
