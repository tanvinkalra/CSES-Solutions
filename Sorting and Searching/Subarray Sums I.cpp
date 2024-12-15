#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    int numSubarrays = 0, left = 0, currentSum = 0;
    for(int right = 0; right < n; ++right) {
        currentSum += nums[right];
        while(left < right && currentSum > target) {
            currentSum -= nums[left];
            left++;
        }
        numSubarrays += (currentSum == target);
    }
    cout << numSubarrays << "\n";
    return 0;
}