#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin >> n;
    vector<int> a(n, 0), idx;
    string s; cin >> s;
    int check = 0, one = 0, two = 0;
    for (int i = 0; i < n; i++) 
        if (s[i] == '(') check++;
        else check--;
    if (check != 0) {
        cout << -1 << endl;
        return;
    }
    int cl1 = 1, cl2 = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {

        }
    }
    cout << 2 << endl;
    cout << a[0];
    for (int i = 1; i < n; i++)
        cout << ' ' << a[i];
    cout << endl;
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