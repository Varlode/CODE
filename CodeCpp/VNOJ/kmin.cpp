#include<bits/stdc++.h>
using namespace std;

int m, n, k, a;
priority_queue<pair<int, int>> pq;

int main() {
    cin >> m >> n >> k;
    for (int i = 1; i <= m; i++) {
        cin >> a;
        pq.push(a);
    }
    for (int i = 1; i <= n; i++) {
        cin >> a;
        pq.push(a);
    }
    while (k-- && pq.size()) {
        cout << pq.top() << endl;
        pq.pop();
    }
}