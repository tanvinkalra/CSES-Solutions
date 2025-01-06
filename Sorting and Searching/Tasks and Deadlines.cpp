#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tasks;
    cin >> tasks;
    vector<pair<int, int>> taskDescription(tasks);
    for(int i = 0; i < tasks; ++i) {
        cin >> taskDescription[i].first >> taskDescription[i].second;
    }
    sort(taskDescription.begin(), taskDescription.end());
    long long maxReward = 0, deadline = 0;
    for(int i = 0; i < tasks; ++i) {
        deadline += taskDescription[i].first;
        maxReward += (taskDescription[i].second - deadline);
    }

    cout << maxReward << "\n";
    return 0;
}