/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

int n, q;
string s;

struct TRIE {
    struct NODE {
        NODE* child[26];
        int exist;
        NODE() {
            for (int i = 0; i < 26; i++) child[i] = NULL;
            exist = 0;
        }
    };

    int cur;
    NODE* root;
    TRIE() : cur(0) {
        root = new NODE();
    };

    void add_string(string &s) {
        NODE* p = root;
        for (auto i : s) {
            int c = i - 'a';
            if (p->child[c] == NULL) p->child[c] = new NODE();

            p = p->child[c];
        }
        p->exist++;
    }

    int dfs(NODE *pos) {
        int res = 0;
        NODE *p = pos;

        for (int i = 0; i < 26; i++) {
            if (p->child[i] == NULL) continue;
            res = max(res, dfs(p->child[i]));
        }

        return res+(p->exist != 0);
    }

} myTree;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        myTree.add_string(s);
    }
    cout << myTree.dfs(myTree.root);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "chuoitu"
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
