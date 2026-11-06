//Zigzag conversion
#include<iostream>
#include<vector>
#include<string>
using namespace std;
string convert(string s,int numRows){
    if(numRows==1)return s;
    int dir=1,r=0;
    vector<string> strs(numRows);
    for(char c:s){
        strs[r].push_back(c);
        r+=dir;
        if(r==0||r==numRows-1)dir=-dir;
    }
    string res;
    for(string str:strs){
        res+=str;
    }
    return res;
}
int main(){
    string s;
    int numRows;
    cin>>s;
    cin>>numRows;
    cout<<convert(s,numRows)<<endl;
    return 0;
}