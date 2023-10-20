#include<bits/stdc++.h>
using namespace std;

#define inf 0x3f3f3f3f

const int N = 1e6;
int n, a[N], deg[N], ans;
vector<int> edges[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++)
            if (abs(a[i]-a[j]) == 1 || abs(a[i]-a[j]==8) || abs(a[i]-a[j])==9) {
                deg[i]++;
                edges[i].push_back(j);
            }

    while (true) {
        
        int ma = -inf, j = inf;
        for (int i = 1; i <= n; i++) if (deg[i] > ma) {
            ma = deg[i];
            j = i;
        }
        if (ma == 0) break;
        for (int v: edges[j]) {
            if (deg[v]) deg[v]--;
        }
        deg[j] = 0;
        ans++;
    }
    cout << ans;
}