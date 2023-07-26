#include<iostream>
using namespace std;

void solve()
{
    long long x, y, n;
    cin >> x >> y >> n;
    x %= n;
    int z = 1;
    while (y > 0) {
        if (y & 1)
            z = z * x % n;
        x = x * x % n;
        y >>= 1;
    }
    cout << z << endl;
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