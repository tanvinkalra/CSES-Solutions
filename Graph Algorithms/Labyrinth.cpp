#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

string bfs(vector<string> &matrix, vector<vector<int>> &visited, int i, int j)
{
    int n = matrix.size(), m = matrix[0].size();
    queue<pair<int, int>> cells;
    cells.push({i, j});
    visited[i][j] = 1;

    while (!cells.empty())
    {
        pair<int, int> currentCell = cells.front();
        int x = currentCell.first, y = currentCell.second;
        cells.pop();

        if (matrix[x][y] == 'B')
        {
            int c = x, d = y;
            string path = "";
            while (matrix[c][d] != 'A')
            {
                switch (visited[c][d])
                {
                case 1:
                    path += 'U';
                    c++;
                    break;
                case 2:
                    path += 'L';
                    d++;
                    break;
                case 3:
                    path += 'D';
                    c--;
                    break;
                case 4:
                    path += 'R';
                    d--;
                    break;
                default:
                    break;
                }
            }
            return path;
        }

        if (x - 1 >= 0 && matrix[x - 1][y] != '#' && visited[x - 1][y] == 0)
        {
            cells.push({x - 1, y});
            visited[x - 1][y] = 1;
        }
        if (y - 1 >= 0 && matrix[x][y - 1] != '#' && visited[x][y - 1] == 0)
        {
            cells.push({x, y - 1});
            visited[x][y - 1] = 2;
        }
        if (x + 1 < n && matrix[x + 1][y] != '#' && visited[x + 1][y] == 0)
        {
            cells.push({x + 1, y});
            visited[x + 1][y] = 3;
        }
        if (y + 1 < m && matrix[x][y + 1] != '#' && visited[x][y + 1] == 0)
        {
            cells.push({x, y + 1});
            visited[x][y + 1] = 4;
        }
    }

    return "";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> matrix(n);
    vector<vector<int>> visited(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i)
    {
        cin >> matrix[i];
    }

    string result = "";

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (matrix[i][j] == 'A')
            {
                result = bfs(matrix, visited, i, j);
                break;
            }
        }
    }

    if (!result.empty())
    {
        cout << "YES\n";
        cout << result.size() << "\n";
        for (int i = result.size() - 1; i >= 0; --i)
        {
            cout << result[i];
        }
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}