#include <bits/stdc++.h>
using namespace std;
#define task "tro"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const int MAX = 100010;
int n;
string s;
int dp[MAX][3];
vector<int> adj[MAX];
stack<pair<int, int>> st;

void dfsMax(int u) {
    dp[u][0] = 1;
    dp[u][1] = 0;
    dp[u][2] = 0;
    if (adj[u].empty()) {
        return;
    }
    for (int v: adj[u]) {
        dfsMax(v);
    }
    if (adj[u].size() == 1) {
        dp[u][0] += max(dp[adj[u][0]][1], dp[adj[u][0]][2]);
        dp[u][1] += max(dp[adj[u][0]][0], dp[adj[u][0]][2]);
        dp[u][2] += max(dp[adj[u][0]][0], dp[adj[u][0]][1]);
    }
    if (adj[u].size() == 2) {
        dp[u][0] += max(dp[adj[u][0]][1] + dp[adj[u][1]][2], dp[adj[u][0]][2] + dp[adj[u][1]][1]);
        dp[u][1] += max(dp[adj[u][0]][0] + dp[adj[u][1]][2], dp[adj[u][0]][2] + dp[adj[u][1]][0]);
        dp[u][2] += max(dp[adj[u][0]][0] + dp[adj[u][1]][1], dp[adj[u][0]][1] + dp[adj[u][1]][0]);
    }
}

void dfsMin(int u) {
    dp[u][0] = 1;
    dp[u][1] = 0;
    dp[u][2] = 0;
    if (adj[u].empty()) {
        return;
    }
    for (int v: adj[u]) {
        dfsMin(v);
    }
    if (adj[u].size() == 1) {
        dp[u][0] += min(dp[adj[u][0]][1], dp[adj[u][0]][2]);
        dp[u][1] += min(dp[adj[u][0]][0], dp[adj[u][0]][2]);
        dp[u][2] += min(dp[adj[u][0]][0], dp[adj[u][0]][1]);
    }
    if (adj[u].size() == 2) {
        dp[u][0] += min(dp[adj[u][0]][1] + dp[adj[u][1]][2], dp[adj[u][0]][2] + dp[adj[u][1]][1]);
        dp[u][1] += min(dp[adj[u][0]][0] + dp[adj[u][1]][2], dp[adj[u][0]][2] + dp[adj[u][1]][0]);
        dp[u][2] += min(dp[adj[u][0]][0] + dp[adj[u][1]][1], dp[adj[u][0]][1] + dp[adj[u][1]][0]);
    }
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	if (fopen(task".inp", "r")) {
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}

    cin >> s; n = s.size();
    for (int i = 0; i <= n - 1; ++i) {
        if (i == 0) {
            st.emplace(i, s[i] - '0');
            continue;
        }
        pair<int, int> &tmp =  st.top();
        if (--tmp.second == 0) st.pop();
        adj[tmp.first].push_back(i);
        if (s[i] != '0') st.emplace(i, s[i] - '0');
    }
    dfsMax(0); cout << max({dp[0][0], dp[0][1], dp[0][2]});
    cout << ' ';
    dfsMin(0); cout << min({dp[0][0], dp[0][1], dp[0][2]});
	return 0;
}
