#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k, apartmentSize;
    cin >> n >> m >> k;
    multiset<int> apartments;
    vector<int> preferences(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> preferences[i];
    }
    sort(preferences.begin(), preferences.end());
    for (int i = 0; i < m; ++i)
    {
        cin >> apartmentSize;
        apartments.insert(apartmentSize);
    }

    int satisfiedApplicants = 0;

    for (int pref : preferences)
    {
        auto it = apartments.lower_bound(pref - k);
        if (it != apartments.end() && *it <= pref + k)
        {
            satisfiedApplicants++;
            apartments.erase(it);
        }
    }

    cout << satisfiedApplicants << "\n";
    return 0;
}