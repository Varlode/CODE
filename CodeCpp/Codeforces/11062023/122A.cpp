#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int lucky[13] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 777};
    int n; cin >> n;
    for (int i = 0; i < 13; i++)
        if (n % lucky[i] == 0) 
        {
            cout << "YES";
            return;
        }
    cout << "NO";
    return;
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