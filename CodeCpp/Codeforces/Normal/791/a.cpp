#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b; cin >> a >> b;
    long long two = 1, three = 1, cnt = 0;
    while (a*three <= b*two) {
        two *= 2;
        three *= 3;
        cnt++;
    }
    cout << cnt;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int t; cin >> t;
    // while (t--)
        solve();
}