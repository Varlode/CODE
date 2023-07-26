#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int a1, b1, a2, b2, a3, b3;
    long long ans = 0;
    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
    for (int i = a1; i <= b1 && i*i <= b3; i++) {
        long long l, r;
        l = i * a2, r = i * b2;
        if (r < a3 || l > b3) continue;
        ans += (min(r, (long long) b3) - max(l, (long long) a3)) / i + 1;
    }
    cout << ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}   