#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;
    long long sum = (n * (n + 1)) / 2;

    if(sum % 2 == 1){
        cout << "NO\n";
        return 0;
    } 

    long long target = sum/2;
    cout << "YES\n";

    vector<long long> set1;
    long long largest = n;
    while(target > 0) {
        long long toSubtract = min(target, largest);
        largest--;
        target -= toSubtract;
        set1.push_back(toSubtract);
    }

    int set1Size = set1.size();
    cout << set1Size << "\n";
    for(int i = 0; i < set1Size; ++i) {
        cout << set1[i] << " ";
    }
    cout << "\n";
    cout << n - set1.size() << "\n";
    int curr = 0;
    for(int i = n; i >= 1; --i) {
        if(curr < set1Size && set1[curr] == i) {
            curr++;
            continue;
        }
        cout << i << " ";
    }
    cout << "\n";


    return 0;
}