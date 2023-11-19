struct DSU {
    #define T_DSU int
    vector<T_DSU> lab;

    DSU(int n): lab(n+10) {};

    void build() {
        for (int i = 1; i <= n; i++) lab[i] = -1;
    }

    int find(int u) {
        return lab[u] <= 0? u: lab[u] = find(lab[u]);
    }

    bool join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (lab[u] > lab[v]) swap(u, v);
            lab[u] += lab[v];
            lab[v] = u;
            return true;
        } 
        return false;
    }
    
};
DSU dsu(n);