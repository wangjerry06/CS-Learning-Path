//set Matrix Zeroes using O(1)space
#include<iostream>
#include<vector>
class Solution{
    public:
    void setZeros(std::vector<std::vector<int>>& matrix){
        size_t c=matrix.size();
        size_t r=matrix[0].size();
        bool row=false,col=false;
        //先扫一遍第一行和第一列，如果有0的话记录下来
        for(size_t i=0;i<r;++i){
            if(matrix[0][i]==0)row=true;
        }
        for(size_t j=0;j<c;++j){
            if(matrix[j][0]==0)col=true;
        }
        //现在开始扫里边的
        for(size_t j=1;j<c;++j){
            for(size_t i=1;i<r;++i){
                if(matrix[j][i]==0){
                    matrix[j][0]=0;
                    matrix[0][i]=0;
                }
            }
        }
        //先清理内部
        for(size_t j=1;j<c;++j){
            for(size_t i=1;i<r;++i){
                if(matrix[j][0]==0||matrix[0][i]==0){
                    matrix[j][i]=0;
                }
            }
        }
        //最后清理0行0列
        if(row){
            for(size_t i=0;i<r;i++)matrix[0][i]=0;
        }
        if(col){
            for(size_t j=0;j<c;j++)matrix[j][0]=0;
        }
    }
};
int main(){
    std::vector<std::vector<int>> v={{1,1,1},{1,0,1},{1,1,1}};
    Solution A;
    A.setZeros(v);
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            std::cout<<v[i][j]<<' ';
        }
        std::cout<<'\n';
    }
    std::cout<<'\n';
    return 0;
}
