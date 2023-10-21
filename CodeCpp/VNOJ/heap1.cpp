#include<bits/stdc++.h>
using namespace std;

#define int long long

int t, n, a, ans;

main() {
    cin >> t;
    while (t--) {
        ans = 0;
        priority_queue<int, vector<int>, greater<int> > pq;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a;
            pq.push(a);
        }
        while (pq.size() > 1) {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            pq.push(a+b);

            ans += a+b;
        }
        cout << ans << endl;
    }
}