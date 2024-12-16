#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool cmp(pair<int, int> const &a, pair<int, int> const &b) {
    return a.second < b.second;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int movies;
    cin >> movies;
    vector<pair<int, int>> timings(movies);
    for(int i = 0; i < movies; ++i) {
        pair<int, int> timing;
        cin >> timing.first >> timing.second;
        timings[i] = timing;
    }
    int watchable = 0, lastWatched = -1;
    sort(timings.begin(), timings.end(), cmp);
    for(int i = 0; i < movies; ++i) {
        if(timings[i].first >= lastWatched) {
            lastWatched = timings[i].second;
            watchable++;
        }
    }

    cout << watchable << "\n";
    return 0;
}