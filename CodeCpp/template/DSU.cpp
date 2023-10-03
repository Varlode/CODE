#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+9;
int par[N], sz[N];

void build_sets() {
    for (int i = 0; i < N; i++) {
        par[i] = i;
        sz[i] = 1;
    }
}

int find_set(int v) {
    return v == par[v] ? v : par[v] = find_set(par[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a, b); // Đặt biến a là gốc của cây có kích cỡ lớn hơn
        par[b] = a;
        sz[a] += sz[b]; // Cập nhật kích cỡ của cây mới gộp lại
    } 
}