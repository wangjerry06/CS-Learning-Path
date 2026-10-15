//trapping rain water
#include<iostream>
#include<vector>
#include<algorithm>
class Solution{
    public:
    int trappingRainWater(std::vector<int> height){
        long long sum=0;
        int h=0;
        int left=0,right=(int)height.size()-1;
        while(left<=right){
            h=std::max(h,std::min(height[left],height[right]));
            sum+=h;
            if(height[left]<height[right])++left;
            else if(height[left]>height[right])--right;
            else{
                if(left!=right)sum+=h;
                ++left;--right;
            }
        }
        for(int x:height){
            sum-=x;
        }
        return (int)sum;
    }
};
int main(){
    std::vector<int> v={4,2,0,3,2,5};
    Solution A;
    std::cout<<A.trappingRainWater(v)<<'\n';
    return 0;
}