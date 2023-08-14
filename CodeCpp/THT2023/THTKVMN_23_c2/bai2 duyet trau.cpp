#include<bits/stdc++.h>
#define ll long long;
#define ld long double;
using namespace std;

int a[100009];
int n, q, ok = false;

bool find(int l, int r, int k) {
    vector<int> pref(r + 1, 0);
    int cnt = 0;
    for (int i = l; i <= r; i++) {
        pref[i] = pref[i - 1] + a[i];
    }
    for (int i = l; i <= r; i++) 
        for (int j = i; j <= r; j++) {
            if (pref[j] - pref[i - 1] == k) {
                cout << i << ' ' << j << endl;
                return true;
            }
        }
    return false;
}

void solve()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <=  q; i++) {
        int r; cin >> r;
        if (r == 1) {
            int u, v; cin >> u >> v;
            a[u] = v;
        } else {
            int u, v, k; cin >> u >> v >> k;
            if (find(u, v, k)) continue;
            else cout << -1 << endl; 
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int t; cin >> t;
    // while (t--)
        solve();
}