#include <bits/stdc++.h>

using namespace std;

int main() {
    string word; cin >> word;

    vector<int> chars(26, 0);
    for(int i = 0; i < word.size(); ++i) {
        chars[word[i] - 'A']++;
    }

    int count = 0;
    for(int i = 0; i < 26; ++i) {
        count += chars[i]%2;
    }
    if(count > 1) {
        cout << "NO SOLUTION\n";
        return 0;
    }
    
    string palindrome = "";
    char unique = '0';

    for(int i = 0; i < 26; ++i) {
        for(int j = 0; j < chars[i]/2; ++j) {
            palindrome += 'A' + i;
        }
        if(chars[i]%2) {
            unique = 'A' + i;
        }
    }

    if(unique != '0') {
        palindrome += unique;
    }

    for(int i = word.size()/2 - 1; i >= 0; --i) {
        palindrome += palindrome[i];
    }

    cout << palindrome << "\n";
    return 0;
}