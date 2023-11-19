#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int n; 
int a[N];
vector<pair<int, int> > p;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n*2; i++) {
            cin >> a[i];
        }
        sort(a, a+2*n);
        p.clear();
        for (int i = 0; i < n; i++) {
            p.push_back({a[i], a[i+n]});
        }
        int sum = 0;
        for (int i = 1; i < n; i++)
            sum += (p[i].first - p[i-1].first) + (p[i].second - p[i-1].second);
        cout << sum << '\n';
        for (pair<int, int> q: p) {
            cout << q.first << ' ' << q.second << '\n';
        }
    }
}