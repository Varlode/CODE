#include <bits/stdc++.h>
using namespace std;

const int N = 202020;
int numStr;
long long ans;
int sum[N][10], sz[N], cntSum[50][10];

int getSum(int id, int x, int y) {
    if (x > y) return 0;
    return sum[id][y] - sum[id][x-1];
}

int getLen(int x, int y) {
    return y-x+1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    cin >> numStr;
    for (int id = 1; id <= numStr; id++) {
        string s; cin >> s;
        sz[id] = (int) s.size();
        for (int pos = 1; pos <= sz[id]; pos++)
            sum[id][pos] += sum[id][pos-1] + (s[pos-1]-'0');
        cntSum[sum[id][sz[id]]][sz[id]]++;
    }

    for (int id = 1; id <= numStr; id++) {
        for (int pos = 1; pos < sz[id]; pos++) {
            int sumNeed = getSum(id, 1, pos) - getSum(id, pos+1, sz[id]);
            int lenNeed = getLen(1, pos)*2 - sz[id];
            if (sumNeed >= 0 && lenNeed) ans += cntSum[sumNeed][lenNeed];
        }
        for (int pos = 2; pos <= sz[id]; pos++) {
            int sumNeed = getSum(id, pos, sz[id]) - getSum(id, 1, pos-1);
            int lenNeed = getLen(pos, sz[id])*2 - sz[id];
            if (sumNeed >= 0 && lenNeed) ans += cntSum[sumNeed][lenNeed];
        }
        ans += cntSum[sum[id][sz[id]]][sz[id]];
    }
    cout << ans;
}