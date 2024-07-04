#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, num;
    cin >> n;
    set<int> distinctNums;
    for(int i = 0; i < n; ++i) {
        cin >> num;
        distinctNums.insert(num);
    }
    cout << distinctNums.size() << "\n";
    return 0;
}