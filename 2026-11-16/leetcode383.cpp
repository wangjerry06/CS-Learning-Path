//ransom note
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
class Solution{
    public:
    bool canConstruct(string ransomNote,string magazine){
        unordered_map<char,int> m;
        for(char c:magazine){
            m[c]++;
        }
        for(char c:ransomNote){
            if(m.count(c)!=0&&m[c]>0){
                m[c]--;
            }
            else return false;
        }
        return true;
    }
};
int main(){
    // 输入格式:第一行 ransomNote,第二行 magazine(对应 LeetCode 383 两个参数)
    // 例:  aa / aab  ->  true
    string ransomNote, magazine;
    getline(cin, ransomNote);
    getline(cin, magazine);
    Solution s;
    cout << (s.canConstruct(ransomNote, magazine) ? "true" : "false") << endl;
    return 0;
}