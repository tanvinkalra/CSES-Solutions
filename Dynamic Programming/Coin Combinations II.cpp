#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, sum;
    cin >> n >> sum;

    int mod = 1e9 + 7;

    vector<int> coins(n + 1);
    for(int i = 1; i < n + 1; ++i) {
        cin >> coins[i];
    }

    int ways[n + 1][sum + 1];

    for(int i = 1; i <= n; ++i) {
         for(int s = 0; s <= sum; ++s) {
            if(s == 0) {
                ways[i][s] = 1;
            } else {
                int option1 = i == 1 ? 0 : ways[i - 1][s];
                int option2 = (coins[i] > s) ? 0 : ways[i][s - coins[i]];
                ways[i][s] = (option1 + option2) % mod;
            }
        }
    }

    cout << ways[n][sum];

    return 0;
}