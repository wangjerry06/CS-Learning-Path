//container with most water
#include<iostream>
#include<vector>
#include<algorithm>
class Solution {
    public:
    int maxArea(std::vector<int>& heights){
        int i=0,j=(int)heights.size()-1;
        int maximum=0;
        while(i<j){
            //water level is limited by the shorter line
            maximum=std::max(maximum,std::min(heights[i],heights[j])*(j-i));
            if(heights[i]<heights[j]){
                ++i;
            }
            else{
                --j;
            }
        }
        return maximum;
    }
};

int main(){
    Solution s;

    // test case 1: expect 49
    std::vector<int> h1={1,8,6,2,5,4,8,3,7};
    std::cout<<"case1: "<<s.maxArea(h1)<<" (expect 49)"<<std::endl;

    // test case 2: expect 1
    std::vector<int> h2={1,1};
    std::cout<<"case2: "<<s.maxArea(h2)<<" (expect 1)"<<std::endl;

    return 0;
}