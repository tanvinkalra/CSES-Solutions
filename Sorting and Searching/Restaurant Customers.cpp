#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int customers;
    cin >> customers;
    map<int, int> customerCount;
    int maxCustomers = 0;
    for(int i = 0; i < customers; ++i) {
        int a, b;
        cin >> a >> b;
        customerCount[a] += 1;
        customerCount[b + 1] -= 1;
    }
    int currentCustomers = 0;
    for(pair<int, int> visitor : customerCount) {
        currentCustomers += visitor.second;
        maxCustomers = max(maxCustomers, currentCustomers);
    }

    cout << maxCustomers << "\n";    
    return 0;
}