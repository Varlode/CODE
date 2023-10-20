#include<bits/stdc++.h>
using namespace std;

const int maxN=1e4+9;
int n, L, P;
pair<int, int> a[maxN];

int solve() {
    int ans = 0;
    priority_queue<int> pq;

    cin >> L >> P;
    for (int i = 1; i <= n; i++) {
        if (L-P > a[i].first) {
            if (pq.empty()) return -1;
            while (L-P > a[i].first && pq.size()) {
                P += pq.top();
                pq.pop();
                ans++;
            }
            if (L-P > a[i].first) return -1;
        }
        pq.push(a[i].second);
    }
    while (L-P > 0 && pq.size()) {
        P += pq.top();
        pq.pop();
        ans++;
    }
    if (L-P > 0 && pq.empty()) return -1;
    return ans;
}

int main() {
    freopen("robot.inp", "r", stdin);
    freopen("robot.out", "w", stdout);
    int T; cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
        sort(a+1, a+n+1, greater<pair<int, int> >());
        cout << solve() << endl;
    }
}