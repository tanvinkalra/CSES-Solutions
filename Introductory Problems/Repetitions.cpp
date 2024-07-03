#include <bits/stdc++.h>


using namespace std;

int main() {
    string sequence;
    cin >> sequence;
    int maxLength = 0, curLen = 0;
    char currentChar = '0';
    for(char s : sequence) {
        if(s == currentChar) {
            curLen++;
        } else {
            curLen = 1;
            currentChar = s;
        }
        maxLength = max(maxLength, curLen);
    }
    cout << maxLength << "\n";
    return 0;
}