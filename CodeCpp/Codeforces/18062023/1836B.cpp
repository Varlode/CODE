#include<bits/stdc++.h>
using namespace std;

void solve()
{
    unsigned long long n, k, g;
    cin >> n >> k >> g;
    unsigned long long coin_each_person = g / 2;
    if (g % 2 == 0) coin_each_person--;
    if (coin_each_person == 0) {
        cout << 0 << endl;
        return;
    }
    unsigned long long real_coin = min((n - 1) * coin_each_person, k * g / coin_each_person * coin_each_person);
    cout << k * g - (unsigned long long) (round((long double) (k * g - real_coin) / g)) * g << endl;
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