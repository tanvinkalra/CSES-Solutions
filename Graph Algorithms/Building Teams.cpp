#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool dfs(int i, vector<vector<int>> &adjList, vector<int> &visited, int color)
{
    visited[i] = color;
    bool isBipartite = true;
    for (int j = 0; j < adjList[i].size(); ++j)
    {
        if (visited[adjList[i][j]] == 0)
        {
            isBipartite = isBipartite && dfs(adjList[i][j], adjList, visited, color == 1 ? 2 : 1);
        }
        else if (visited[adjList[i][j]] == color)
        {
            return false;
        }
    }
    return isBipartite;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjList(n);

    for (int i = 0; i < m; ++i)
    {
        int src, dest;
        cin >> src >> dest;
        adjList[src - 1].push_back(dest - 1);
        adjList[dest - 1].push_back(src - 1);
    }

    vector<int> visited(n, 0);

    for (int i = 0; i < n; ++i)
    {
        if (visited[i] == 0)
        {
            bool res = dfs(i, adjList, visited, 1);
            if (!res)
            {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        cout << visited[i] << " ";
    }

    return 0;
}