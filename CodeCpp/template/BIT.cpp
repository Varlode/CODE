#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+9;
int bit[N*4];
int n;

int get(int p) {
    int idx = p, ans = 0;
    while (idx > 0) {
        ans += bit[idx];
        idx -= (idx & (-idx));
    }
    return ans;
}
void update(int u, int v) {
    int idx = u;
    while (idx <= n) {
        bit[idx] += v;
        idx += (idx & (-idx));
    }
}
void updateRange(int l, int r, int v) {
    update(l, v);
    update(r + 1, -v);
}