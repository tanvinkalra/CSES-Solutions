#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> coins(n);
    for(int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end());
    long long smallestCoin = 1;
    for(int i = 0; i < n && smallestCoin >= coins[i]; ++i) {
        smallestCoin += coins[i];
    }
    cout << smallestCoin << "\n";
    return 0;
}