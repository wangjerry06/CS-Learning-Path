//交易逆序对的总数
#include<iostream>
#include<vector>
class Solution{
    public:
    int reversePairs(std::vector<int>& record){
        if(record.size()<2)return 0;
        std::vector<int> tmp(record.size());
        return sortCount(record,tmp,0,(int)record.size());
    }
    long long sortCount(std::vector<int> &a,std::vector<int> &tmp,int l,int r){
        if(r-l<=1)return 0;
        int m=l+(r-l)/2;
        long long left=sortCount(a,tmp,l,m);
        long long right=sortCount(a,tmp,m,r);

        long long cross=0;
        int i=l,j=m,k=l;
        while(i<m&&j<r){
            if(a[i]<=a[j]){
                tmp[k++]=a[i++];
            }
            else{
                cross+=m-i;
                tmp[k++]=a[j++];
            }
        }
        while(i<m)tmp[k++]=a[i++];
        while(j<r)tmp[k++]=a[j++];
        for(int t=l;t<r;++t)a[t]=tmp[t];
        return left+right+cross;
    }
};

int main(){
    Solution s;
    std::vector<int> record={7,5,6,4};
    std::cout<<"record: ";
    for(int x:record)std::cout<<x<<" ";
    std::cout<<"\nreverse pairs: "<<s.reversePairs(record)<<std::endl;
    return 0;
}