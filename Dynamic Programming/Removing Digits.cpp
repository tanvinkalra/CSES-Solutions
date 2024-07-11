#include <bits/stdc++.h>

using namespace std;

vector<int> getDigits(int num) {
    vector<int> digits;
    while(num > 0) {
        if(num%10 != 0)
            digits.push_back(num%10);
        num /= 10;
    }
    return digits;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> num;

    int ways[num + 1];
    ways[0] = 0;

    for(int i = 1; i <= num; ++i) {
        vector<int> digits = getDigits(i);
        int moves = INT_MAX;
        for(int j = 0; j < digits.size(); ++j) {
            moves = min(moves, ways[i - digits[j]]);
        }
        ways[i] = 1 + moves;
    }

    cout << ways[num];

    return 0;
}