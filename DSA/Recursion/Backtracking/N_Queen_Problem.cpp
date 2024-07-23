#include <iostream>
#include <vector>

using namespace std;

void printSolution(vector<vector<char>> board, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << " " << board[i][j];
    }
    cout << endl;
  }
  cout << "\n\n";
}

bool isSafe(int row, int col, vector<vector<char>> &board, int n)
{
  // check krna hain ki current cell pr queen rkhna possible hain ki nhi
  int i = row;
  int j = col;

  while (j >= 0)
  {
    if (board[i][j] == 'Q')
      return false;
    j--;
  }
  j = col;

  // Upper Diagonal check
  while (i >= 0 && j >= 0)
  {
    if (board[i][j] == 'Q')
      return false;
    i = i - 1;
    j = j - 1;
  }

  j = col;
  i = row;
  // Lower Diagonal check
  while (i < n && j >= 0)
  {
    if (board[i][j] == 'Q')
      return false;
    i = i + 1;
    j = j - 1;
  }

  // kahi pr queen nhi mili mtlb place kr skte hain
  return true;
}
void solve(vector<vector<char>> &board, int col, int n)
{
  // base case
  if (col >= n)
  {
    printSolution(board, n);
    return;
  }

  for (int row = 0; row < n; row++)
  {
    if (isSafe(row, col, board, n))
    {
      // rakh do queen
      board[row][col] = 'Q';
      // recursion
      solve(board, col + 1, n);
      // backtracking
      board[row][col] = '-';
    }
  }
}

int main()
{
  int n = 4;
  vector<vector<char>> board(n, vector<char>(n, '-'));
  int col = 0;

  solve(board, col, n);

  return 0;
}
