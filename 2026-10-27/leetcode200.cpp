//numbers of island
#include<vector>
class Solution{
    void dfs(std::vector<std::vector<char>>& grid,int i,int j){
        int n=(int)grid.size();
        int m=(int)grid.size();
        if(i<0||i>=n||j<0||j>=m||grid[i][j]=='0')return;
        grid[i][j]='0';
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
    }
    int numsIsland(std::vector<std::vector<char>>&& grid){
        int n=(int)grid.size();
        int m=(int)grid.size();
        int ans=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    ++ans;
                }
            }
        }
        return ans;
    }
};
