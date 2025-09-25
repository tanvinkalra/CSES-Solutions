#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

pair<int, int> dfs(int i, vector<vector<int>> &adjList, vector<int> &visited, vector<int> &parent)
{
    pair<int, int> loopEnds = {-1, -1};
    visited[i] = 1;
    for (int j = 0; j < adjList[i].size(); ++j)
    {
        if (visited[adjList[i][j]] == 0)
        {
            parent[adjList[i][j]] = i;
            pair<int, int> traversal = dfs(adjList[i][j], adjList, visited, parent);
            if (traversal.first != -1)
            {
                loopEnds = traversal;
            }
        }
        else if (adjList[i][j] != parent[i])
        {
            return {i, adjList[i][j]};
        }
    }

    return loopEnds;
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
    vector<int> parent(n, -1);

    for (int i = 0; i < n; ++i)
    {
        if (visited[i] == 0)
        {
            pair<int, int> loopEnds = dfs(i, adjList, visited, parent);
            if (loopEnds.first != -1)
            {
                // Track the path
                int start = parent[loopEnds.second] == -1 ? loopEnds.second : loopEnds.first;
                int finish = start == loopEnds.first ? loopEnds.second : loopEnds.first;
                vector<int> path = {start};
                int currentNode = finish;
                while (currentNode != start)
                {
                    path.push_back(currentNode);
                    currentNode = parent[currentNode];
                }
                path.push_back(currentNode);
                cout << path.size() << "\n";
                for (int city : path)
                {
                    cout << city + 1 << " ";
                }
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}