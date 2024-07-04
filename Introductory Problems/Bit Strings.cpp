#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; 
    int MOD = 1e9 + 7;
    cin >> n;
    long long bitStrings = 1;
    for(int i = 1; i <= n; ++i) {
        bitStrings *= 2;
        bitStrings %= MOD;
    }
    cout << bitStrings << "\n";
    return 0;
}