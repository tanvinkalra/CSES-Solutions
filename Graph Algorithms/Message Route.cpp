#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

void bfs(int i, vector<vector<int>> &adjList, vector<int> &visited)
{
    visited[i] = i + 1;
    queue<int> computers;
    computers.push(i);

    while (!computers.empty())
    {
        int computer = computers.front();
        computers.pop();

        for (int j = 0; j < int(adjList[computer].size()); ++j)
        {
            if (visited[adjList[computer][j]] == 0)
            {
                computers.push(adjList[computer][j]);
                visited[adjList[computer][j]] = computer + 1;
            }
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
    bfs(0, adjList, visited);

    if (visited[n - 1] == 0)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        vector<int> path;
        path.push_back(n);
        int index = n - 1;
        while (index != 0)
        {
            path.push_back(visited[index]);
            index = visited[index] - 1;
        }
        cout << path.size() << "\n";
        for (int i = path.size() - 1; i >= 0; --i)
        {
            cout << path[i] << " ";
        }
    }

    return 0;
}