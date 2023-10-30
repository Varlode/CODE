#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define id se.se
#define d fi
#define s se.fi

const int N = 1e6;
int n, f[N];
pair<int, pair<int, int> > a[N];
vector<int> vec_ans;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].s;
    for (int i = 1; i <= n; i++) cin >> a[i].d;
    for (int i = 1; i <= n; i++) a[i].id = i;
    sort(a+1, a + n+1);
    int curT = 0, ans = 0;
    for (int i = 1; i <= n; i++) cout << a[i].d << ' ' << a[i].s << ' ' << a[i].id << endl;
    for (int i = 1; i <= n; i++) {
        if (curT + a[i].s <= a[i].d) {
            curT += a[i].s;
            f[a[i].id] = 1;
            ans++;
            vec_ans.push_back(a[i].id);
        } 
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++) 
        if (f[a[i].id] == 0) vec_ans.push_back(a[i].id);
    cout << vec_ans[0]; for (int i = 1; i < n; i++) cout << ' ' << vec_ans[i];
}