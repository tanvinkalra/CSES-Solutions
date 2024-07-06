#include <bits/stdc++.h>

using namespace std;

int main() {
    string word;
    cin >> word;
    set<string> permutations({""});

    for(size_t i = 0; i < word.size(); ++i) {
        set<string> newPermutations;
        for(string permutation : permutations) {
            for(size_t j = 0; j <= permutation.size(); ++j) {
                string newPermute = permutation;
                newPermute.insert(j, 1, word[i]);
                newPermutations.insert(newPermute);
            }
        }
        permutations = newPermutations;
    }

    cout << permutations.size() << "\n";
    for(string permutation : permutations) {
        cout << permutation << "\n";
    }
    return 0;
}
