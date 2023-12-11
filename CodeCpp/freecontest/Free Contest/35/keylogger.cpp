/*
          _
   ______/ \-.   _         _ __ _         _    _
.-/     (    o\_//        / l..l \       / >--< \
 l  ___  \_/\---'         \/ ll \/       \l  \ l/
 l_ll  l_ll                l_''_l         l_ll_l

*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    deque<char> truoc, sau;
    char c;
    while (cin >> c) {
        if (c != '<' && c != '>' && c !='-') {
            truoc.push_back(c);
        }
        else {
            if (c == '<' && truoc.size()) {
                sau.push_front(truoc.back());
                truoc.pop_back();
            }
            if (c == '>' && sau.size()) {
                truoc.push_back(sau.front());
                sau.pop_front();
            }
            if (c == '-' && truoc.size()) truoc.pop_back();
        }
    }
    for (char c: truoc) cout << c;
    for (char c: sau) cout << c;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
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
