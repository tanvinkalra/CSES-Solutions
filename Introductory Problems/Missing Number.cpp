#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n, 0);

    for(int i = 0; i < n - 1; ++i) {
        cin >> nums[i];
    }

    int missingNumber = 0;

    for(int i = 0; i < n; ++i) {
        missingNumber ^= (nums[i] ^ (i + 1));
    }

    cout << missingNumber << "\n";

}