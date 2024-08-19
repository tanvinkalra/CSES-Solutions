#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    long long maxSum = INT_MIN, curSum = 0;

    for(int i = 0; i < n; ++i) {
        curSum += nums[i];
        maxSum = max(maxSum, curSum);
        if(curSum < 0) {
            curSum = 0;
        }
    }

    cout << maxSum << "\n";    
    return 0;
}