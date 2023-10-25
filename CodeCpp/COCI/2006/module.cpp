#include<bits/stdc++.h>
using namespace std;

int cnt[43];
int ans;

int main() {
    for (int i = 1; i <= 10; i++) {
        int a; cin >> a;
        cnt[a%42]++;
    }
    for (int i = 0; i <= 42; i++) {
        if (cnt[i]) ans++;
    }
    cout << ans;
}