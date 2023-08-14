#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e4+9;
int n, d[maxN], c[maxN], L, P;

int main() {
    freopen("thamhiem.inp", "r", stdin);
    freopen("thamhiem.out", "w", stdout);
    int T; cin >> T;
    while (T--) {
        priority_queue<int> pq;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> d[i] >> c[i];
        }
        cin >> L >> P;
        int cnt = 0, pre = L-P, sum = P;
        for (int i = n; i >= 1; i--) {
            while (!pq.empty() && L-sum > d[i]) {
                sum += pq.top(); pq.pop();
                pre = L-sum;
                cnt++;
            }
            if (pq.empty() && pre > d[i]) {
                cnt = -1;
                break;
            }
            if (L-sum <= 0) break;
            pq.push(c[i]);
        }
        while (!pq.empty() && pre > 0) {
            sum += pq.top(); pq.pop();
            pre = L-sum;
            cnt++;
        }
        if (pq.empty() && pre > 0) {
            cnt = -1;
        }
        cout << cnt << endl;
    }
}