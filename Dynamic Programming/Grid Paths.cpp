#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int mod = 1e9 + 7;

    vector<string> grid(n);
    for(int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    if(grid[0][0] == '*') {
        cout << "0\n";
        return 0;
    }

    int dp[n][n];
    dp[0][0] = 1;

    for(int i = 1; i < n; ++i) {
        if(grid[0][i] == '*') {
            dp[0][i] = 0;
        } else {
            dp[0][i] = dp[0][i - 1];
        }

        if(grid[i][0] == '*') {
            dp[i][0] = 0;
        } else {
            dp[i][0] = dp[i - 1][0];
        }
    }

    for(int i = 1; i < n; ++i) {
        for(int j = 1; j < n; ++j) {
            if(grid[i][j] == '*') {
                dp[i][j] = 0;
            } else {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
            }
        }
    }

    cout << dp[n - 1][n - 1];

    return 0;
}