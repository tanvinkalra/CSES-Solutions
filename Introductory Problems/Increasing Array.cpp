#include <bits/stdc++.h>


using namespace std;

int main() {
    int n; 
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    long long moves = 0, last = 0;
    for(int i = 0; i < n; ++i) {
        if(nums[i] < last) {
            moves += last - nums[i];
        } else {
            last = nums[i];
        }
    }
    cout << moves << "\n";
    return 0;
}