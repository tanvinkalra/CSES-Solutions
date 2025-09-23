#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void dfs(int i, vector<vector<int>> &adjList, vector<int> &visited)
{
    visited[i] = 1;
    for (int j = 0; j < adjList[i].size(); ++j)
    {
        if (visited[adjList[i][j]] == 0)
        {
            dfs(adjList[i][j], adjList, visited);
        }
    }
    return;
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
    vector<int> connectedComponents;

    for (int i = 0; i < n; ++i)
    {
        if (visited[i] == 0)
        {
            dfs(i, adjList, visited);
            connectedComponents.push_back(i);
        }
    }

    cout << connectedComponents.size() - 1 << "\n";
    for (int i = 0; i < connectedComponents.size() - 1; ++i)
    {
        cout << connectedComponents[i] + 1 << " " << connectedComponents[i + 1] + 1 << "\n";
    }

    return 0;
}