//Integer to Roman
#include<utility>
#include<string>
#include<iostream>
using namespace std;
string intToRoman(int num){
    pair<int,string> table[]={{1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},{90,"XC"},{50,"L"},{40,"XL"},{10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"}};
    string ans;
    for(auto& [val,sym]:table){
        while(val<=num){
            ans+=sym;
            num-=val;
        }
    }
    return ans;
}

int main(){
    int num;
    while(cin>>num){
        if(num<1||num>3999){
            cout<<"输入超出范围 (1 <= num <= 3999)"<<endl;
            continue;
        }
        cout<<intToRoman(num)<<endl;
    }
    return 0;
}