#include<bits/stdc++.h>
using namespace std;

int cntp, cntn;

void solve()
{
    int n; cin >> n;
    cntp = 0; cntn = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) 
        if (a[i] == 1) cntp++;
        cntn++;
    if (cntp >= cntn) {
        if (cntn & 1) cout << 1 << endl;
        else cout << 0 << endl;
    } else {
        int tmp = (cntp + cntn) / 2;
        cntp += tmp;
        cntn -= tmp;
        
        if (cntp >= cntn)
            if (cntn & 1) cout << 1 + tmp << endl;  
            else cout << tmp << endl;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--)
        solve();
}   