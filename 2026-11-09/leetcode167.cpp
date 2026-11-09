//two sum II - input array is sorted
#include<iostream>
#include<vector>
std::vector<int> twoSum(std::vector<int>& numbers, int target){
    int l=0,r=(int)numbers.size()-1;
    std::vector<int> ans(2);
    while(l<r){
        int sum=numbers[l]+numbers[r];
        if(sum<target)++l;
        else if(sum>target)--r;
        else break;
    }
    ans={l+1,r+1};
    return ans;
}
int main(){
    int n;
    if(!(std::cin>>n))return 0;
    std::vector<int> numbers(n);
    for(int i=0;i<n;++i)std::cin>>numbers[i];
    int target;
    std::cin>>target;
    std::vector<int> ans=twoSum(numbers,target);
    std::cout<<ans[0]<<" "<<ans[1]<<std::endl;
    return 0;
}