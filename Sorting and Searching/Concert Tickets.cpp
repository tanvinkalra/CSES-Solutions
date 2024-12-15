#include <iostream>
#include <vector>
#include <iterator>
#include <set>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int numTickets, numCustomers, ticketPrice, customerExpectation;
    cin >> numTickets >> numCustomers;
    multiset<int> ticketPrices;
    for(int i = 0; i < numTickets; ++i) {
        cin >> ticketPrice;
        ticketPrices.insert(ticketPrice);
    }
    for(int i = 0; i < numCustomers; ++i) {
        cin >> customerExpectation;
        if(ticketPrices.size() == 0) {
            cout << "-1\n";
            continue;
        }
        auto it = ticketPrices.lower_bound(customerExpectation);
        if(it == ticketPrices.begin() && *it > customerExpectation) {
            cout << "-1";
        } else if(*it > customerExpectation || it == ticketPrices.end()) {
            it--;
            cout << *it;
            ticketPrices.erase(it);
        } else {
            cout << *it;
            ticketPrices.erase(it);
        }
        cout << "\n";
    }

    return 0;
}