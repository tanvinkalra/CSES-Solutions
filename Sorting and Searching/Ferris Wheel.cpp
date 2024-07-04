#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> weights(n);
    for(int i = 0; i < n; ++i) {
        cin >> weights[i];
    }
    sort(weights.begin(), weights.end());

    int lo = 0, hi = n - 1, gondolas = 0;
    while(lo < hi) {
        int sum = weights[lo] + weights[hi];
        if(sum <= x) {
            lo++;
        } 
        hi--;
        gondolas++;
    }

    if(lo == hi) {
        gondolas++;
    }
    cout << gondolas << "\n";
    return 0;
}