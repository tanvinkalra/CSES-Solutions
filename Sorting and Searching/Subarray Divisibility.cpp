#include <iostream>
#include <limits.h>
#include <vector>
#include <map>
#include <algorithm>


using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    long long validSubarrays = 0;
    map<int, int> remainders;
    remainders[0] = 1;
    long long runningSum = 0;
    vector<long long> nums(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
        runningSum += nums[i];
        int remainder = (((runningSum % n) + n) % n);
        validSubarrays += remainders[remainder];
        remainders[remainder]++;
    }
    cout << validSubarrays << "\n";
    return 0;
}