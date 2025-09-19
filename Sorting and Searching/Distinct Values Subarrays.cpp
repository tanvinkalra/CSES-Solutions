#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    long long distinctSubarrays = 0, l = 0, r = 0;
    set<int> currentNums;
    for (; r < n; ++r)
    {
        while (currentNums.find(nums[r]) != currentNums.end())
        {
            currentNums.erase(nums[l]);
            l++;
        }
        currentNums.insert(nums[r]);
        distinctSubarrays += r - l + 1;
    }
    cout << distinctSubarrays << "\n";
    return 0;
}