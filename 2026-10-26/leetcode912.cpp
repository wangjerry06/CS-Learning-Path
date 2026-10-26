//sort an array
#include<iostream>
#include<vector>
#include<algorithm>
class Solution{
    void quickSort(std::vector<int>& nums,int lo,int hi){
        if(lo>=hi)return;
        int pivot=nums[lo+(hi-lo)/2];
        int i=lo-1,j=hi+1;
        while(true){
            do{i++;}while(nums[i]<pivot);
            do{j--;}while(nums[j]>pivot);
            if(i>=j)break;
            std::swap(nums[i],nums[j]);
        }
        quickSort(nums,lo,j);
        quickSort(nums,j+1,hi);
    }
    public:
    std::vector<int> sortArray(std::vector<int>& nums){
        int n=(int)nums.size()-1;
        quickSort(nums,0,n);
        return nums;
    }
};
int main(){
    std::vector<int> nums={5,1,1,2,0,0};
    Solution A;
    A.sortArray(nums);
    for(int n:nums){
        std::cout<<n<<' ';
    }
    std::cout<<'\n';
    return 0;
}