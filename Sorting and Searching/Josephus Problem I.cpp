#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    queue<int> q;
    for(int i = 1; i <= n; ++i) {
        q.push(i);
    }

    while(!q.empty()) {
        int top = q.front();
        q.pop();
        q.push(top);
        cout << q.front() << " ";
        q.pop();
    }
    
    return 0;
}