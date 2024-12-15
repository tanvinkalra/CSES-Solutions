#include <iostream>
#include <vector>
#include <map>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> nums(n);
    map<int, int> numPosition;
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
        numPosition[nums[i]] = i;
    }
    int iterations = 1;
    for(int i = 2; i <= n; ++i) {
        if(numPosition[i - 1] > numPosition[i]) {
            iterations++;
        }
    }

    cout << iterations << "\n";
    return 0;
}