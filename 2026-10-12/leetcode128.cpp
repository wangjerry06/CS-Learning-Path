//longest consicutive sequance
#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
class Solution{
    public:
    int longestSequance(const std::vector<int>& nums){
        int maximum=0;
        std::unordered_set<int> set;
        for(int n:nums){
            set.insert(n);
        }
        for(auto& elem:set){
            if(!set.count(elem-1)){
                int len=1;
                int cur=elem;
                while(set.count(cur+1)){
                    ++cur;
                    ++len;
                }
                maximum=std::max(maximum,len);
            }
        }
        return maximum;
    }
};
int main(){
    std::vector<int> v={100,4,200,1,3,2};
    Solution A;
    std::cout<<A.longestSequance(v)<<'\n';
    return 0;
}