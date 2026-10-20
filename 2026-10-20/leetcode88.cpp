//merge sorted array
#include<iostream>
#include<vector>
void mergeSortedArray(std::vector<int>& nums1,int m,std::vector<int> nums2,int n){
    int count1=nums1.size();
    int i=m-1,j=n-1;
    while(i>=0&&j>=0){
        if(nums1[i]>nums2[j]){
            nums1[count1-1]=nums1[i];
            --count1,--i;
        }
        else{
            nums1[count1-1]=nums2[j];
            --count1,--j;
        }
    }
    if(i<0){
        for(int k=0;k<=j;++k){
            nums1[k]=nums2[k];
        }
    }
}
int main(){
    std::vector<int> nums1={1,2,3,0,0,0};
    std::vector<int> nums2={2,5,6};
    mergeSortedArray(nums1,3,nums2,3);
    for(int v:nums1){
        std::cout<<v<<' ';
    }
    return 0;
}