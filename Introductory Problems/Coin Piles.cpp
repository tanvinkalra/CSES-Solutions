#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tests;
    cin >> tests;
    while(tests--) {
        long long a, b;
        cin >> a >> b;
        if((a + b) % 3 != 0 || (a * 2) < b || (b * 2) < a) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}