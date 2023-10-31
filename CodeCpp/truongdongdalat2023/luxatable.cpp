#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
int n, a[N], b[N];
vector<int> dt;
vector<pair<int, int> > real_vector;
int ans = 1e9;

int kount() {
    int cnt = 0;
    for (int k = 1; k <= n; k++) {
        if (a[k] == b[k]) continue;
        if (cnt >= ans) return 1e9;

        int l = k, r;
        for (r = k; r <= n; r++) if (a[r] == b[r]) break; r--;
        k = r;
        if (l == r) cnt++; else
        while (l < r) {
            if (b[l] != a[l+1] && b[r] != a[r-1]) {
                cnt += 2; 
                l++; r--;
            } else if (l+1 == r) {
                if (b[l] == a[l+1] && b[r] == a[r-1]) cnt += 3;
                else cnt += 2; 
                l++; r--;
            } else {
                if (b[l] == a[l+1]) cnt += 2; else cnt++;
                if (b[r] == a[r-1]) cnt += 2; else cnt++;
                if (l+1 == r-1) cnt--;
                l++; r--;
            }
            if (cnt >= ans) return 1e9;
        }
    }
    return cnt;
}

void build(int i, int j) {
    for (int k = 1; k <= n; k++) {
        if (k&1) b[k] = real_vector[i].second;
        else b[k] = real_vector[j].second;
    }
}

void solve() {
    cin >> n;
    unordered_map<int, int> um;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dt.push_back(a[i]);
        um[a[i]]++;
    }
    sort(dt.begin(), dt.end());
    dt.erase(unique(dt.begin(), dt.end()), dt.end());
    for (int i: dt) real_vector.push_back({um[i], i});
    sort(real_vector.begin(), real_vector.end(), greater<pair<int, int>>());
    
    for (int i = 0; i < real_vector.size(); i++) for (int j = i+1; j < real_vector.size(); j++) {
        build(i, j);
        ans = min(ans, kount());
        build(j, i);
        ans = min(ans, kount());
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("luxtable.inp", "r", stdin);
    freopen("luxtable.out", "w", stdout);
    int t; cin >> t;
    while (t--) {
        solve();
    }   
}