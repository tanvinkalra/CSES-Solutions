#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    int prices[n];
    for(int i = 0; i < n; ++i) {
        cin >> prices[i];
    }

    int pages[n];
    for(int i = 0; i < n; ++i) {
        cin >> pages[i];
    }

    int dp[n + 1][x + 1];


    for(int i = 0; i <= n; ++i) {
        for(int price = 0; price <= x; ++price) {
            if(price == 0 || i == 0) {
                dp[i][price] = 0;
            } else {
                int option1 = i == 1 ? 0 : dp[i - 1][price];
                int option2 = prices[i - 1] > price ? 0 : (pages[i - 1] + dp[i - 1][price - prices[i - 1]]);
                dp[i][price] = max(option1, option2);
            }
        }
    }

    cout << dp[n][x];

    return 0;
}