struct BIT {
    #define T_BIT int
    vector<T_BIT> bit; 

    BIT(int n): bit(n) {};

    T_BIT get(int p) {
        int idx = p;
        T_BIT ans = 0;
        while (idx > 0) {
            ans += bit[idx];
            idx -= (idx & (-idx));
        }
        return ans;
    }

    void update(int u, T_BIT v) {
        int idx = u;
        while (idx <= n) {
            bit[idx] += v;
            idx += (idx & (-idx));
        }
    }

    T_BIT getRange(int l, int r) {
        return get(r) - get(l-1);
    }

    void updateRange(int l, int r, int v) {
        update(l, v);
        update(r + 1, -v);
    }
};
BIT bit(n);