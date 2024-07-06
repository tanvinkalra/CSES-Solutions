#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; 
    cin >> n;

    int trailingZeroes = 0;
    
    for (int i = 5; n / i >= 1; i *= 5)
        trailingZeroes += n / i;

    cout << trailingZeroes << "\n";

    return 0;
}