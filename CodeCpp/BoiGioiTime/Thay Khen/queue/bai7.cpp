#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair<ll, ll>
#define iii pair<ll, ii>

int main() {
    int test; cin >> test;
    while (test--) {
        map<int, int> m;
        priority_queue<ii, vector<ii>> pq;
        int k; string s;
        cin >> k; cin >> s;
        for (char c: s) m[c]++;
        for (int i = 'A'; i <= 'Z'; i++) {
            if (m[i]) pq.push({m[i]*m[i], i});
        }
        while (k--) {
            ii tmp = pq.top(); pq.pop();
            m[tmp.second]--;
            pq.push({m[tmp.second]*m[tmp.second], tmp.second});
        }
        int ans = 0;
        while (pq.size()) {
            ans += (pq.top()).first;
            pq.pop();
        }
        cout << ans << endl;
    }
}