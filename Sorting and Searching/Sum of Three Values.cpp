#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, target, num;
    cin >> n >> target;
    vector<pair<int, int>> nums(n);
    for(int i = 0; i < n; ++i) {
        cin >> num;
        nums[i] = {num, i + 1};
    }
    sort(nums.begin(), nums.end());
    bool isPossible = false;

    for(int i = 0; i < n - 2 && !isPossible; ++i) {
        int lo = i + 1, hi = n - 1;
        while(lo < hi) {
            int sum = nums[i].first + nums[lo].first + nums[hi].first;
            if(sum == target) {
                cout << nums[i].second << " "  << nums[lo].second << " " << nums[hi].second << "\n";
                isPossible = true;
                break;
            } else if(sum > target) {
                hi--;
            } else {
                lo++;
            }
        }
    }

    if(!isPossible) {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}