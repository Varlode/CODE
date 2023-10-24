#include<bits/stdc++.h>
using namespace std;

int n, k;
int a[500][500];
int par[500];

struct node {
    int u, v, c;
    node(int a, int b, int x) {
        u = a; v = b; c = x;
    }
};
vector<node> e;

int find(int u) {
    return (par[u] == u)? u: par[u] = find(par[u]);
}

int join(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return 0;
    par[v] = u;
    return 1;
}

int main() {
    cin >> n >> k;

    // Khởi tạo DSU
    for (int i = 1; i <= n; i++) par[i] = i;
    
    // Nhập ma trận
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) 
            cin >> a[i][j];

    // Tạo cạnh từ ma trận
    for (int i = 1; i <= n; i++) 
        for (int j = i + 1; j <= n; j++) 
            e.push_back(node(i, j, a[i][j]));

    // Tiến hành dựng cây khung của k tập
    int cnt = n;
    // có n tập ban đầu quản lý n đỉnh
    sort(e.begin(), e.end(), [&](node a, node b){return a.c < b.c;});

    int ans = 0;
    for (auto ei: e) {
        if (find(ei.u) == find(ei.v)) continue;
        // 2 đỉnh cùng tập thì nó không ảnh hưởng đến khoảng cách min
        if (cnt == k) {
            ans = ei.c;
            break;
            // khi đã chia ra k tập thì ra kết quả ko cần duyệt nữa
        }
        cnt -= join(ei.u, ei.v);
        // mỗi lần hợp 2 tập sẽ giảm số tập xuống 1
    }
    cout << ans;
}