#include <bits/stdc++.h>
using namespace std;

const int N = 101;
string s;
int dp[8][N], mem[8][N], a[N];


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    cin >> s;
    int trace = -1;
    memset(mem, -1, sizeof mem);
    for (int i = 1; i <= (int) s.size(); i++) a[i] = s[i-1]-'0';
    dp[a[1]%8][1] = 1;
    for (int i = 2; i <= (int) s.size(); i++) {
        dp[a[i]%8][i] = 1;
        for (int j = 0; j < 8; j++) {
            if (dp[j][i-1]) {
                dp[(j*10+a[i])%8][i] = 1;
                mem[(j*10+a[i])%8][i] = j;
                dp[j][i] = 1;
                mem[j][i] = j;
            }
        }
        if (dp[0][i]) {
            trace = i;
            break;
        }
    }
    if (dp[0][1]) trace = 1;
    if (trace == -1) cout << "NO";
    else {
        cout << "YES\n";
        vector<int> ans;
        int mod = 0;
        while (true) {
            if (mem[mod][trace] == -1 || mem[mod][trace] != mod)
                ans.push_back(a[trace]);
            if (mem[mod][trace] == -1) break;
            mod = mem[mod][trace];
            trace--;
        }
        reverse(ans.begin(), ans.end());
        for (int i: ans) cout << i;
    }

}