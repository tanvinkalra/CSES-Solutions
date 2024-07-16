#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, target;
    cin >> n >> target;

    int nums[n];

    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    bool isFound = false;
    map<int, int> indexes;

    for(int i = 0; i < n; ++i) {
        int remainder = target - nums[i];
        if(remainder < 0 || indexes.find(remainder) == indexes.end()) {
            indexes[nums[i]] = i + 1;
        }else {
            isFound = true;
            cout << indexes[remainder] << " " << i + 1;
            break;
        }
    }

    if(!isFound) {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}

