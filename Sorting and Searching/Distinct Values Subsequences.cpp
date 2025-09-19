#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    map<int, int> frequencies;
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
        frequencies[nums[i]]++;
    }
    int MOD = 1e9 + 7;
    long long distinctSubsequences = 1;

    for (pair<int, int> freq : frequencies)
    {
        distinctSubsequences *= (freq.second + 1);
        distinctSubsequences %= MOD;
    }

    cout << (distinctSubsequences - 1) % MOD << "\n";

    return 0;
}