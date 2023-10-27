#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int a;
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 1; i <= n; i++) {
        cin >> a; pq.push(a);
    }
    int ans = 0;
    while (pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        ans += a+b;
        pq.push(a+b);
    }
    cout << ans;
}