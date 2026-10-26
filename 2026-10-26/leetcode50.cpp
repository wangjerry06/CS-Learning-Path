//Pow(x,n)
#include<iostream>
double fastpow(double y,long long n){
    if(n==1)return y;
    double half=fastpow(y,n/2);
    if(n%2==0)return half*half;
    else return half*half*y;
}
double myPow(double x,int n){
    if(n==0)return 1;
    if(n<0){
        long long N=n;
        N=-N;
        return 1.0/fastpow(x,N);
    }
    return fastpow(x,n);
}
int main(){
    std::cout<<myPow(2.0,-2)<<'\n';
    return 0;
}