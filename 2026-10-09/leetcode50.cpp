//Pow(x,n)
#include<iostream>
class SolutionA{
    private:
    double myPow2(double x,long long n){
        if(n==0)return 1.0;
        double half=myPow2(x,n/2);
        return (n%2!=0)?half*half*x:half*half;
    }
    public:
    double myPow(double x,int n){
        long long N=n;
        if(N<0)return 1.0/myPow2(x,-N);
        if(N==0)return 1.0;
        return myPow2(x,N);
    }
};
class SolutionB{
    public:
    double myPow(double x,int n){
        long long N=n;
        if(N<0){
            x=1.0/x;
            N=-N;
        }
        double ans=1.0;
        while(N>0){
            if(N&1==1)ans*=x;
            x*=x;
            N>>=1;
        }
        return ans;
    }
};
int main(){
    double x1=2.0,x2=2.1,x3=2.0;
    int n1=10,n2=3,n3=-2;
    SolutionA A;
    SolutionB B;
    std::cout<<A.myPow(x1,n1)<<'\n'<<A.myPow(x2,n2)<<'\n'<<A.myPow(x3,n3)<<'\n';
    std::cout<<B.myPow(x1,n1)<<'\n'<<B.myPow(x2,n2)<<'\n'<<B.myPow(x3,n3)<<'\n';
    return 0;
}