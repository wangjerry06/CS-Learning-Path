//happy number
#include<iostream>
#include<unordered_set>
using namespace std;
class Solution{
    public:
    int digitSquareSum(int n){
        int sum=0;
        while(n>0){
            int dig=n%10;
            n/=10;
            sum+=dig*dig;
        }
        return sum;
    }
    bool happy(int n,unordered_set<int>& seen){
        if(n==1)return true;
        if(seen.count(n)!=0)return false;
        seen.insert(n);
        return happy(digitSquareSum(n),seen);
    }
    bool isHappy(int n){
        unordered_set<int> seen;
        return happy(n,seen);
    }
};

int main(){
    int n;
    cin>>n;
    Solution sol;
    cout<<(sol.isHappy(n)?"true":"false")<<endl;
    return 0;
}