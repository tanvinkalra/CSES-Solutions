#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, sum;
    cin >> n >> sum;
    int MOD = 1e9 + 7;
    vector<int> coins(n);
    for(int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    vector<int> ways(sum + 1, -1);
    ways[0] = 1;

    for(int i = 1; i <= sum; ++i) {
        int current = 0;
        for(int j = 0; j < n; ++j) {
            if(i - coins[j] >= 0 && ways[i - coins[j]] != -1) {
                current += (ways[i - coins[j]] % MOD);
                current %= MOD;
            }
        }
        if(current != 0) {
            ways[i] = current;
        }
    }

    if(ways[sum] == -1) {
        cout << "0\n";
    } else {
        cout << ways[sum] << "\n";
    }

    return 0;
}