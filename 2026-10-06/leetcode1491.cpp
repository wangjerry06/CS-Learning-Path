//average salary excluding the minimum and maximum salary
#include<iostream>
#include<vector>
class Solution{
    public:
    int average(const std::vector<int>& salary){
        int max=salary[0];
        int min=salary[0];
        int sum=0;
        size_t n=salary.size()-2;
        for(int x:salary){
            if(x>max)max=x;
            if(x<min)min=x;
            sum+=x;
        }
        double ans=(sum-max-min)/n;
        return ans;
    }
};
int main(){
    std::vector<int> v={1000000,2000000,3000000,4000000,5000000,6000000};
    Solution A;
    std::cout<<A.average(v)<<'\n';
    return 0;
}