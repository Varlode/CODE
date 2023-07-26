#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5+5;
int b[maxN][2];
vector<int> a(maxN, 0);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k; cin >> n >> k;
    for (int  i = 1; i <= n; i++) cin >> a[i];
    a[n + 1] = 1e9 + 5;
    sort(a.begin(), a.begin() + n + 1);
    int j = 0;
    int i = 1; while (i < n) {
        b[j][0] = a[i];
        b[j][1] = upper_bound(a.begin(), a.begin() + n + 1, a[i]) - lower_bound(a.begin(), a.begin() + n + 1, a[i]);
        i = upper_bound(a.begin(), a.begin() + n + 1, a[i]) - a.begin();
        j++;
    }
    long long res1 = 0, res2 = 0;
    for (int i = 0; i < j; i++)
        if (b[i][1] >= k) {
            res1++;
            res2 += b[i][0];
        }
    cout << res1 << " " << res2;
}
