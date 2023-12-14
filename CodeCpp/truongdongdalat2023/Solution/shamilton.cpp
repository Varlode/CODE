#include <bits/stdc++.h>
using namespace std;
#define task "shamilton"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const int MAX = 200020;
int n;
string s;
vector<int> res;
vector<int> adj[26][26];

void dfs(int u) {
    for (int c = 0; c < 26; ++c) {
        while (adj[u][c].size() > 0) {
            int id = adj[u][c].back(); adj[u][c].pop_back();
            dfs(c); res.push_back(id);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	if (fopen(task".inp", "r")) {
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        adj[s[0] - 'a'][s.back() - 'a'].push_back(i);
    }
    dfs(s[0] - 'a');
    if (res.size() != n) {
        cout << "-1";
        return 0;
    }
    reverse(res.begin(), res.end());
    for (int &id: res) {
        cout << id << ' ';
    }

	return 0;
}
