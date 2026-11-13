//valid sodoku
#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
    bool isValidSudoku(vector<vector<char>>& board){
        vector<vector<int>> rowSet(9,vector<int>(9,0));
        vector<vector<int>> colSet(9,vector<int>(9,0));
        vector<vector<int>> boxSet(9,vector<int>(9,0));

        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                char c=board[i][j];
                if(c=='.')continue;

                int box=(i/3)+(j/3)*3;

                int pos=(c-'0')-1;
                if(rowSet[i][pos]>0)return false;
                if(colSet[j][pos]>0)return false;
                if(boxSet[box][pos]>0)return false;

                rowSet[i][pos]++;
                colSet[j][pos]++;
                boxSet[box][pos]++;
            }
        }
        return true;
    }
};