//find the differences
#include<iostream>
#include<string>
#include<algorithm>

char findTheDifference(std::string word1,std::string word2){
    std::sort(word1.begin(),word1.end());
    std::sort(word2.begin(),word2.end());
    //先重排之后再比较
    char ans='\0';
    //很重要的一点，char类型的空字符是\0
    int i=0;
    while(i<=word1.size()&&word1[i]==word2[i]){//要先判断越界再迭代
        ++i;
    }
    ans=word2[i];
    return ans;
}

int main(){
    using namespace std;
    string word1="";string word2="";
    cin>>word1>>word2;

    char res=findTheDifference(word1,word2);
    cout<<res<<'\n';
}