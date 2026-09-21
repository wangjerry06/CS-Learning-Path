//merge string alternately

#include<iostream>
#include<string>

void mergeAlternately(std::string word1, std::string word2, std::string& ans);//直接在ans上修改，不用拷贝
//先声明后写函数
int main(){
    using namespace std;//main里没有敏感名称
    string word1="";
    string word2="";
    cin>>word1>>word2;
    string ans="";
    mergeAlternately(word1,word2,ans);//调用Ans
    cout<<ans<<'\n';//输出调用完之后的Ans
    return 0;
}

void mergeAlternately(std::string word1, std::string word2, std::string& ans){
    int num1=word1.length();
    int num2=word2.length();
    int i=0;
    while(num1>0||num2>0){//只有两个都读完了才会停止
        if(num1>0){//如果还剩就继续
            ans.push_back(word1[i]);//读取往后放
        }
        if(num2>0){//同理
            ans.push_back(word2[i]);
        }
        ++i;--num1;--num2;//迭代
    }
//void不用返回，使用&的时候直接修改
}