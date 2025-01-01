#include <iostream>
#include <vector>
#include <iterator>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int streetLength, numTrafficLights, trafficLight;
    cin >> streetLength >> numTrafficLights;
    set<int> positions;
    positions.insert(0);
    positions.insert(streetLength); 
    multiset<int> maxStreetLength;
    maxStreetLength.insert(streetLength);
    for(int i = 0; i < numTrafficLights; ++i) {
       cin >> trafficLight;
       positions.insert(trafficLight);
       auto iter = positions.find(trafficLight);
       int previousValue = *prev(iter);
       int nextValue = *next(iter);
       maxStreetLength.erase(maxStreetLength.find(nextValue - previousValue));
       maxStreetLength.insert(nextValue - trafficLight);
       maxStreetLength.insert(trafficLight - previousValue);
       cout << *maxStreetLength.rbegin() << " ";
    }
    cout << "\n";
    return 0;
}