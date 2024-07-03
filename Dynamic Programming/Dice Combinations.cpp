#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    int M = 1e9 + 7;
    vector<int> ways(1e6 + 5, 0);
    ways[0] = 1;
    for(int i = 1; i <= N; ++i) {
        int num = 0;
        for(int j = 1; j <= 6; ++j) {
            if(i - j >= 0) {
                num += ways[i - j];
                num %= M;
            } else {
                break;
            }
        }
        ways[i] = num;
    }
    cout << ways[N] << "\n";
    return 0;
}