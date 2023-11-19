#include <bits/stdc++.h>
using namespace std;

int n, maximum = -1e9, min_time = 1e9; string ans;
string name[1010]; int score[1010];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    map<string, int> ms, ok;
    for (int i = 1; i <= n; i++) {
        cin >> name[i] >> score[i];
        ms[name[i]] += score[i];
    }
    for (int i = 1; i <= n; i++) maximum = max(maximum, ms[name[i]]);
    int tmp = 0;
    for (int i = 1; i <= n; i++) if (ms[name[i]] == maximum) ok[name[i]] = 1;
    ms.clear();
    for (int i = 1; i <= n; i++) {
        if (!ok[name[i]]) continue;
        ms[name[i]] += score[i];
        if (ms[name[i]] >= maximum) {
            cout << name[i];
            break;
        }
    }
}