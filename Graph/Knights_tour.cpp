#include<bits/stdc++.h>
using namespace std;

//function to display the 2-d array
void display(vector<vector<int>>& chess) {
  for (int i = 0; i < chess.size(); i++) {
    for (int j = 0; j < chess.size(); j++) {
      cout << chess[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void printKnightTour(vector<vector<int>>& chess, int n, int r, int c, int upcommingMove) {

  if (r < 0 or c < 0 or r >= n or c >= n or chess[r][c] != 0) {
    return;
  }
  if (upcommingMove == n * n) {
    chess[r][c] = upcommingMove;
    display(chess);
    chess[r][c] = 0;
    return;
  }
  chess[r][c] = upcommingMove;
  printKnightTour(chess, n, r - 2, c + 1, upcommingMove + 1);
  printKnightTour(chess, n, r - 1, c + 2, upcommingMove + 1);
  printKnightTour(chess, n, r + 1, c + 2, upcommingMove + 1);
  printKnightTour(chess, n, r + 2, c + 1, upcommingMove + 1);
  printKnightTour(chess, n, r + 2, c - 1, upcommingMove + 1);
  printKnightTour(chess, n, r + 1, c - 2, upcommingMove + 1);
  printKnightTour(chess, n, r - 1, c - 2, upcommingMove + 1);
  printKnightTour(chess, n, r - 2, c - 1, upcommingMove + 1);
  chess[r][c] = 0;

}

int main() {
  int n, r, c;
  cin >> n >> r >> c;
  vector<vector<int>> chess(n, vector<int>(n, 0));
  int upcommingMove = 0;
  printKnightTour(chess, n, r, c, upcommingMove);
}