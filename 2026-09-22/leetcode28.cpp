//find the index of tne first occurrence in a string
#include<iostream>
#include<string>

int strStr(std::string haystack,std::string needle){
    size_t pos=haystack.find(needle);//推荐使用size_t，size_t是能跟着平台走的能表示任何对象大小的无符号整型
    //s.find()是在string里找子串
    if (pos==std::string::npos){//find找不到的输出
        return -1;
    }
    else{
        return (int)pos;//一定要转，因为我们定义这个函数用的是int
    }
}

int main(){
    using namespace std;
    string str1,str2;
    cin>>str1>>str2;
    int ans=strStr(str1,str2);
    cout<<ans<<'\n';
    return 0;
}