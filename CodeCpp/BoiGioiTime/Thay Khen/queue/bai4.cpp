#include<bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define fi first
#define se second
int main() {
    int test; cin >> test;
    while (test--) {
        int l, r; cin >> l >> r;
        queue<ii> q;
        map<int, int> vstd;
        q.push({l, 0});
        while (q.size()) {
            ii tmp = q.front();
            if (tmp.fi-1 == r) {
                cout << tmp.se+1 << endl;
                break;
            } else {
                if (tmp.fi-1 > 0 && vstd[tmp.fi-1] == 0) {
                    vstd[tmp.fi-1] = 1;
                    q.push({tmp.fi-1, tmp.se+1});
                }
            }
            if (tmp.fi*2 == r) {
                cout << tmp.se+1 << endl;
                break;
            } else {
                if (tmp.fi*2 < 1e9 && vstd[tmp.fi*2] == 0) {
                    vstd[tmp.fi*2] = 1;
                    q.push({tmp.fi*2, tmp.se+1});
                }
            }
            q.pop();
        }
    }
}