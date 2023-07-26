#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin >> n;
    int one, two, m;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (x == 1) one = i;
        if (x == 2) two = i;
        if (x == n) m = i;
    }
    if (m > one && m > two) {
        cout << m << " " << max(one, two) << endl;
        return;
    } else if (m < one && m < two) {
        cout << m << " " << min(one, two) << endl;
        return;
    } else {
        cout << m << " " << m << endl;
    }
    
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