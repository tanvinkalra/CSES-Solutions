#include <iostream>
#include <limits.h>
#include <vector>
#include <map>


using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> songs(n);
    for(int i = 0; i < n; ++i) {
        cin >> songs[i];
    }
    map<int, int> uniqueSongs;
    int longestSequence = 0, lo = 0;
    for(int hi = 0; hi < n; ++hi) {
        while(uniqueSongs[songs[hi]] > 0) {
            uniqueSongs[songs[lo]]--;
            lo++;
        }
        uniqueSongs[songs[hi]] = 1;
        longestSequence = max(longestSequence, hi - lo + 1);
    }
    cout << longestSequence << "\n";
    return 0;
}