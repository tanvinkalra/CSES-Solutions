#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int mod = 1e9 + 7;

    int n;
    cin >> n;
    int sum = (n * (n + 1)) / 2;

    if(sum % 2 == 1){
        cout << 0;
        return 0;
    } 

    int target = sum/2;

    int dp[n + 1][target + 1];

    for(int i = 0; i <= n; ++i) {
        dp[i][0] = 1;
    }

    for(int i = 1; i <= target; ++i) {
        dp[0][i] = 0;
    }

    for(int i = 1; i <= n; ++i) {
        for(int sum = 1; sum <= target; ++sum) {
            if(sum - i >= 0) {
                dp[i][sum] = (dp[i - 1][sum - i] + dp[i - 1][sum]) % mod;
            } else {
                dp[i][sum] = dp[i - 1][sum];
            }
        }
    }

    if(dp[n][target] % 2 == 0) {
        cout << dp[n][target] / 2;
    } else {
        long long ways = (mod + dp[n][target]) / 2;
        cout << ways % mod;
    }

    return 0;
}

