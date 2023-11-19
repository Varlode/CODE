    #include<bits/stdc++.h>
    using namespace std;

    int n, m;

    int main() {
        cin >> n >> m;
        int init = n, buy = 0;
        while (init >= m) {
            buy += init/m;
            init = init/m + init%m;
        }
        if (n < m) cout << n;
        else cout << n + buy;
    }