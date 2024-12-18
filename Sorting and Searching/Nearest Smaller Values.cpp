#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> nums(n), nearestSmallest(n, 0);
    stack<int> s;
    
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    for(int i = n - 1; i >= 0; --i) {
        while(!s.empty() && nums[s.top()] > nums[i]) {
            nearestSmallest[s.top()] = i + 1;
            s.pop();
        }
        s.push(i);
    }

    for(int i = 0; i < n; ++i) {
        cout << nearestSmallest[i] << " ";
    }
    cout << "\n";

    return 0;
}