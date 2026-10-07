//check if it is a straight line
#include<iostream>
#include<vector>
class Solution{
    public:
    bool checkStraightLine(const std::vector<std::vector<int>>& coordinates){
        int x0=coordinates[0][0],y0=coordinates[0][1];
        int x1=coordinates[1][0],y1=coordinates[1][1];
        for(size_t i=1;i<coordinates.size();++i){
            int xi=coordinates[i][0],yi=coordinates[i][1];
            if((y1-y0)*(xi-x0)!=(x1-x0)*(yi-y0))return false;
        }
        return true;
    }
};
int main(){
    std::vector<std::vector<int>> v={{1,1},{2,2},{3,4},{4,5},{5,6},{7,7}};
    Solution A;
    std::cout<<std::boolalpha<<A.checkStraightLine(v)<<'\n';
    return 0;
}