#include<bits/stdc++.h>
using namespace std;

bool ok = true;

void solve()
{
    int n; cin >> n;
    if (n == 0) {
        ok = false;
        return;
    }
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    vector<int> go(1, 0), wait;
    for (int i = 1; i <= n; i++) {
        while (!wait.empty() && wait.back() - go.back() == 1) {
            go.push_back(wait.back());
            wait.pop_back();
        }
        if (a[i] - go.back() == 1) {
            go.push_back(a[i]);
        } else {
            wait.push_back(a[i]);
        }
    }
    while (!wait.empty() && wait.back() - go.back() == 1) {
        go.push_back(wait.back());
        wait.pop_back();
    }
    if (wait.empty()) cout << "yes" << endl;
    else cout << "no" << endl;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while (ok)    
        solve();
}   