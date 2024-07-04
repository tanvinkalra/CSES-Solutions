#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; 
    cin >> n;
    
    while(n--) {
        int row, col;
        cin >> row >> col;
        long long currentNum = max(row, col);
        long long precedingNum = (currentNum - 1);
        int direction = currentNum % 2;
        if(direction == 0) {
            if(col == currentNum) {
                cout << (precedingNum * precedingNum) + row << "\n";
            }
            else {
                cout << (precedingNum * precedingNum) + currentNum + currentNum - col << "\n";
            }
        } else {
            if(row == currentNum) {
                cout << (precedingNum * precedingNum) + col << "\n";
            }
            else {
                cout << (precedingNum * precedingNum) + currentNum + currentNum - row << "\n";
            }
        }
    }
    return 0;
}