//Rotate Image
#include<iostream>
#include<vector>
#include<utility>
using namespace std;
class Solution{
    public:
    void rotate(vector<vector<int>>& matrix){
        int n=(int)matrix.size();
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<n/2;++j){
                swap(matrix[i][j],matrix[i][n-1-j]);
            }
        }
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if(!(cin>>n))return 0;

    vector<vector<int>> matrix(n,vector<int>(n));
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>matrix[i][j];
        }
    }

    Solution sol;
    sol.rotate(matrix);

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(j)cout<<' ';
            cout<<matrix[i][j];
        }
        cout<<'\n';
    }
    return 0;
}