#include<bits/stdc++.h>
using namespace std;

const int maxN = 101, maxW = 100001;
long long f[maxN][maxW];
int w[maxN], v[maxN];

int main() {
    int n, W; cin >> n >> W;
    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= W; j++) {
            if(j + w[i] <= W) f[i + 1][j + w[i]] = max(f[i][j] + v[i], f[i + 1][j + w[i]]);
            f[i + 1][j] = max(f[i][j], f[i + 1][j]);
        }
    }
    cout << f[n][W];
}
