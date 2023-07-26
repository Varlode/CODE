#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin >> n;
    vector<long long> a(n + 2), l(n + 2), r(n + 2), st;
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && a[i] <= a[st.back()]) {
            st.pop_back();
        }
        if (st.empty()) {
            l[i] = 0;
            st.push_back(i);
        } else {
            l[i] = st.back();
            st.push_back(i);
        }
    }
    st.clear();
    for (int i = n; i >= 1; i--) {
        while (!st.empty() && a[i] <= a[st.back()]) {
            st.pop_back();
        }
        if (st.empty()) {
            r[i] = n + 1;
            st.push_back(i);
        } else {
            r[i] = st.back();
            st.push_back(i);
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, (r[i] - l[i] - 1) * a[i]);
    }
    cout << ans << endl;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--)
        solve();
}   