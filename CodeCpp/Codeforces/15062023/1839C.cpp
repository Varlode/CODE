#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (a[n - 1] == 1) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    int i = n - 2, s = 0;
    cout << 0;
    while (i >= 0)
    {
       if (a[i] == 0) {
            cout << " " << 0;
            i--;
            continue;
       }
       if (a[i] == 1) {
            s = 1;
            int j = i - 1;
            while (j >= 0 && a[j] == 1) {
                cout << " " << 0;
                j--;
                s++;
            }
            cout << " " << s;
            i = j;
       }
    }
    cout << endl;
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