#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int min = 0, sum = 0;
    int col = matrix[0].size(), row = matrix.size();

    // int num=-1;
    for (int i = 0; i < col; i++)
    {
        sum = matrix[0][i];
        cout << sum;
        for (int j = 0; j < row; j++)
        {
            if (j > 0 && j < row)
                if (matrix[i][j] > matrix[i][j + 1])
                    sum = sum + matrix[i][j + 1];
                else if (matrix[i][j] > matrix[i][j - 1])
                    sum += matrix[i][j - 1];
                else
                    sum += matrix[i][j];
            else if (j == 0)
                if (matrix[])
        }
        min = min + num;
    }
}