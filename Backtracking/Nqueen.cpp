#include<bits/stdc++.h>
using namespace std;
bool queenIsSafe(vector<vector<int>> chess, int row,int col){

    for(int i = row-1,j=col;i >=0;i--){
        if(chess[i][j]==1){
            return false;
        }
    }

    for(int i = row-1,j = col-1;i>=0 and j >=0;i--,j--){
        if(chess[i][j] == 1){
            return false;
        }
    }
    for(int i = row-1,j = col+1;i>=0 and j<chess.size();i--,j++){
        if(chess[i][j] == 1){
            return false;
        }
    }
    return true;
}
void printNQueens(vector<vector<int>> &chess, string qsf, int i) {
  if(i == chess.size()){
      cout<<qsf<<". "<<endl;
      return;
  }
  for(int j = 0;j<chess.size();j++){
     if(queenIsSafe(chess,i,j)){
        chess[i][j] = 1;
        printNQueens(chess,qsf+to_string(i)+"-"+to_string(j)+", ",i+1);
        chess[i][j] = 0;
     }
  }

}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> chess(n, vector<int> (n));

  printNQueens(chess, "", 0);

}