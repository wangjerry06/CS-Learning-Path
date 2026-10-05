//matrix diagonal sum
#include<iostream>
#include<vector>
class Solution{
    public:
    int diagonalSum(std::vector<std::vector<int>>& mat){
        int sum=0;
        size_t count=mat.size();
        for(size_t i=0;i<count;++i){
            if(i==count-i-1){
                sum+=mat[i][i];
            }
            else{
                sum=sum+mat[i][i]+mat[i][count-i-1];
            }
        }
        return sum;
    }
};
int main(){
    std::vector<std::vector<int>> v={{1,2,3},{4,5,6},{7,8,9}};
    Solution A;
    std::cout<<A.diagonalSum(v)<<'\n';
    return 0;
}