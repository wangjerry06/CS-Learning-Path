//Find winner on a Tic
#include<iostream>
#include<vector>
#include<string>
class Solution{
    public:
    bool check(char board[3][3],char player){
        for(int r=0;r<3;++r){
            if(board[r][0]==player&&board[r][1]==player&&board[r][2]==player)return true;
        }
        for(int c=0;c<3;++c){
            if(board[0][c]==player&&board[1][c]==player&&board[2][c]==player)return true;
        }
        if(board[0][0]==player&&board[1][1]==player&&board[2][2]==player)return true;
        if(board[0][2]==player&&board[1][1]==player&&board[2][0]==player)return true;
        return false;
    }
    std::string tictactoe(std::vector<std::vector<int>> moves){
        char board[3][3]={};
        for(size_t i=0;i<moves.size();++i){
            int row=moves[i][0];
            int col=moves[i][1];
            board[row][col]=(i%2==0)?'A':'B';
        }
        if(check(board,'A'))return "A";
        if(check(board,'B'))return "B";
        return moves.size()==9?"Draw":"Pending";
    }
};
int main(){
    std::vector<std::vector<int>> v={{0,0},{2,0},{1,1},{2,1},{2,2}};
    Solution A;
    std::cout<<A.tictactoe(v)<<'\n';
}