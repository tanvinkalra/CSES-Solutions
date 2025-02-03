#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void dfs(vector<string>& matrix, vector<vector<int>>& visited, int i, int j) {
    int n = matrix.size(), m = matrix[0].size();
    visited[i][j] = 1;
    if(i - 1 >= 0 && matrix[i - 1][j] == '.' && visited[i - 1][j] == 0) {
        dfs(matrix, visited, i - 1, j);
    }
    if(j - 1 >= 0 && matrix[i][j - 1] == '.' && visited[i][j - 1] == 0) {
        dfs(matrix, visited, i, j - 1);
    }
    if(i + 1 < n && matrix[i + 1][j] == '.' && visited[i + 1][j] == 0) {
        dfs(matrix, visited, i + 1, j);
    }
    if(j + 1 < m && matrix[i][j + 1] == '.' && visited[i][j + 1] == 0) {
        dfs(matrix, visited, i, j + 1);
    }

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> matrix(n);
    vector<vector<int>> visited(n, vector<int>(m, 0));

    for(int i = 0; i < n; ++i) {
        cin >> matrix[i];
    }

    int rooms = 0;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(matrix[i][j] == '.' && visited[i][j] == 0) {
                rooms++;
                dfs(matrix, visited, i, j);
            }
        }
    }

    cout << rooms << "\n";



    return 0;
}