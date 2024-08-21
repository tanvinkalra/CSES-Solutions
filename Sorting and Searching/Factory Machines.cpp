#include <iostream>
#include <limits.h>
#include <vector>
#include <map>

using namespace std;

bool isPossible(vector<long long>& processingTimes, long long products, long long time) {
    long long manufactured = 0;
    for(long long processingTime : processingTimes) {
        manufactured += time/processingTime;
    }
    return manufactured >= products;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long machines, products;
    cin >> machines >> products;
    long long maxTime = INT_MAX;
    vector<long long> processingTimes(machines);
    for(long long i = 0; i < machines; ++i) {
        cin >> processingTimes[i];
        maxTime = min(maxTime, processingTimes[i]);
    }

    long long lo = 1, hi = maxTime * products;
    long long minimumTime = maxTime * products;
    while(lo <= hi) {
        long long mid = lo + (hi - lo)/2;
        if(isPossible(processingTimes, products, mid)) {
            minimumTime = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << minimumTime << "\n";
    return 0;
}