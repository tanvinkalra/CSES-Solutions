#include <iostream>
#include <vector>

using namespace std;

bool isPossible(int i, int j, vector<string> &chessboard)
{
    if (chessboard[i][j] == '*' || chessboard[i][j] == '#')
    {
        return false;
    }
    for (int k = 0; k < i; ++k)
    {
        if (chessboard[k][j] == '#')
            return false;
    }

    for (int k = 1; i - k >= 0; k++)
    {
        if (j - k >= 0 && chessboard[i - k][j - k] == '#')
            return false;
        if (j + k < 8 && chessboard[i - k][j + k] == '#')
            return false;
    }

    return true;
}

int findWays(vector<string> &chessboard, int row)
{
    if (row == 8)
    {
        return 1;
    }
    int numWays = 0;
    for (int col = 0; col < 8; col++)
    {
        if (isPossible(row, col, chessboard))
        {
            chessboard[row][col] = '#';
            numWays += findWays(chessboard, row + 1);
            chessboard[row][col] = '.';
        }
    }

    return numWays;
}

int main()
{
    vector<string> chessboard(8);
    for (int i = 0; i < 8; ++i)
    {
        cin >> chessboard[i];
    }
    cout << findWays(chessboard, 0) << "\n";
    return 0;
}