#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long minimumTotalCost = 0;
    int n; cin >> n;
    vector<int> sticks(n);
    for(int i = 0; i < n; ++i) {
        cin >> sticks[i];
    }
    sort(sticks.begin(), sticks.end());
    for(int i = 0; i < n; ++i) {
        minimumTotalCost += abs(sticks[i] - sticks[n/2]);
    }
    cout << minimumTotalCost << "\n";
    return 0;
}