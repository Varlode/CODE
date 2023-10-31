#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int n, k, q;
int init[N];
int tmp[2*N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("rotgame.inp", "r", stdin);
    // freopen("rotgame.out", "w", stdout);
    cin >> n >> k >> q; 
    for (int i = 1; i <= n; i++) init[i] = i-1; 
    for (int i = 1; i <= n; i++) cout << init[i] << ' '; cout << endl;
    for (int d = 1; d <= q; d++) {
        int A, X; cin >> A >> X;
        if (A == 1) {
            if (X > 0) {
                X %= k; if (X == 0) X = k;
                for (int i = 1; i < n; i += k) {
                    for (int j = i; j < i+k; j++) tmp[j] = tmp[j+k] = init[j];
                    for (int j = i; j < i+k; j++) init[j] = tmp[j+k-X];   
                }
            } else {
                X = -X; X %= k; if (X == 0) X = k;
                for (int i = 1; i < n; i += k) {
                    for (int j = i; j < i+k; j++) tmp[j] = tmp[j+k] = init[j];
                    for (int j = i; j < i+k; j++) init[j] = tmp[j+X];  
                }
            }
        } else {
            if (X > 0) {
                X %= n; if (X == 0) X = n;
                for (int j = 1; j <= n; j++) tmp[j] = tmp[j+n] = init[j];
                for (int j = 1; j <= n; j++) init[j] = tmp[j+n-X];     
            } else {
                X = -X; X %= n; if (X == 0) X = n;
                for (int j = 1; j <= n; j++) tmp[j] = tmp[j+n] = init[j];
                for (int j = 1; j <= n; j++) init[j] = tmp[j+X]; 
            }
        }
        for (int i = 1; i <= n; i++) cout << init[i] << ' '; cout << endl;
    } 
    unordered_map<int, int> um;
    for (int i = 1; i <= n; i++) {
        int z; cin >> z;
        um[init[i]] = z;
    }
    for (int i = 1; i <= n; i++) 
        cout << um[i-1] << ' ';
}