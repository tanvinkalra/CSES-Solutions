#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> coins(N);
    for(int i = 0; i < N; ++i) {
        cin >> coins[i];
    }
    vector<int> minCoins(X + 1, -1);
    minCoins[0] = 0;
    for(int i = 1; i <= X; ++i) {
        for(int j = 0; j < N; ++j) {
            if(i - coins[j] >= 0 && minCoins[i - coins[j]] != -1) {
                if(minCoins[i] == -1) {
                    minCoins[i] = minCoins[i - coins[j]] + 1;
                } else {
                    minCoins[i] = min(minCoins[i], minCoins[i - coins[j]] + 1);
                }
            }
        }
    }
    cout << minCoins[X] << "\n";
    return 0;
}