#include<bits/stdc++.h>
using namespace std;

struct hcn {
    pair<int, int> a[4];
    int x, y, u, v;
    void build() {
        a[0] = make_pair(x, y);    //up_le
        a[1] = make_pair(u, y);    //up_ri
        a[2] = make_pair(x, v);    //do_le
        a[3] = make_pair(u, v);    //do_ri
    }
};

bool inside(pair<int, int> g, hcn h) {
    if (g.first < h.x || h.u < g.first) return false;
    if (g.second < h.v || h.y < g.second) return false;
    return true;
}


int main() {
    freopen("hcn.inp", "r", stdin);
    freopen("hcn.out", "w", stdout);
    hcn h1, h2;
    cin >> h1.x >> h1.y >> h1.u >> h1.v;
    cin >> h2.x >> h2.y >> h2.u >> h2.v;

    h1.build();
    h2.build();

    vector<pair<int, int> > g;
    for (int i = 0; i < 4; i++) {
        if (inside(h1.a[i], h2))
            g.push_back(h1.a[i]);
        if (inside(h2.a[i], h1))
            g.push_back(h2.a[i]);
    }

    if (g.size() < 2) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    
    int x = 1e9, y = -1e9, u = -1e9, v = 1e9;
    for (int i = 0; i < g.size(); i++) {
        x = min(x, g[i].first);
        y = max(y, g[i].second);
        u = max(u, g[i].first);
        v = min(v, g[i].second);
    }

    if (x == u) {
        if (x == h1.x) {
            u = h2.u;
        } if (x == h2.x) {
            u = h1.u;
        }
    }
    if (y == v) {
        if (v == h1.v) {
            y = h2.y;
        } if (v == h2.v) {
            y = h1.y;
        }
    }

    cout << x << ' ' << y << ' ' << u << ' ' << v;
}