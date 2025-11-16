#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int numCustomers;
    cin >> numCustomers;
    vector<pair<int, int>> timings(numCustomers);
    vector<int> allocatedRooms(numCustomers, 0);
    map<int, set<int>> roomRegister;
    map<int, int> roomAvailability;
    for (int i = 0; i < numCustomers; ++i)
    {
        cin >> timings[i].first >> timings[i].second;
        roomAvailability[timings[i].first]++;
        roomRegister[timings[i].first].insert(i + 1);
        roomAvailability[timings[i].second + 1]--;
        roomRegister[timings[i].second + 1].insert(-(i + 1));
    }
    int maxRooms = 0, currentRooms = 0;
    for (pair<int, int> avail : roomAvailability)
    {
        currentRooms += avail.second;
        maxRooms = max(maxRooms, currentRooms);
    }
    set<int> availableRooms;
    for (int i = 1; i <= maxRooms; ++i)
    {
        availableRooms.insert(i);
    }

    for (pair<int, set<int>> entry : roomRegister)
    {
        for (int customer : entry.second)
        {
            if (customer < 0)
            {
                availableRooms.insert(allocatedRooms[abs(customer + 1)]);
            }
            else
            {
                set<int>::iterator it = availableRooms.begin();
                int room = *it;
                availableRooms.erase(it);
                allocatedRooms[customer - 1] = room;
            }
        }
    }

    cout << maxRooms << "\n";
    for (int i = 0; i < numCustomers; ++i)
    {
        cout << allocatedRooms[i] << " ";
    }
    cout << "\n";

    return 0;
}