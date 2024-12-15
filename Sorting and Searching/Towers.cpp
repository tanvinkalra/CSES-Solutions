#include <iostream>
#include <vector>
#include <iterator>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int numCubes;
    cin >> numCubes;
    vector<int> cubes(numCubes);
    multiset<int> towers;
    for(int i = 0; i < numCubes; ++i) {
       cin >> cubes[i];
    }
    for(int i = 0; i < numCubes; ++i) {
        auto it = towers.upper_bound(cubes[i]);
        if (it != towers.end()) {
            towers.erase(it);
        } 
        towers.insert(cubes[i]);
    }
    cout << towers.size() << "\n";
    return 0;
}