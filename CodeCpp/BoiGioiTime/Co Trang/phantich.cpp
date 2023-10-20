#include<bits/stdc++.h>
using namespace std;

const int N = 1e3;
int n, m, a[N], ans;
map<int, int> mp;
vector<int> s[2];

void recur(int id, int ed, int sum, int i) {
    if (id > ed) return;
    for (int stt = 0; stt <= 1; stt++) {
        sum += a[id]*stt;
        if (stt) s[i].push_back(sum);
        recur(id+1, ed, sum, i);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    recur(1, n/2, 0, 0);
    recur(n/2+1, n, 0, 1);
    for (int i: s[0]) mp[i]++;
    for (int i: s[1]) ans += mp[m-i];
    for (int i: s[1]) mp[i]++;
    ans += mp[m];
    cout << ans;   
}

/*
0 0 0 0 1
0 0 0 1 0
0 0 0 1 1
0 0 1 0 0
0 0 1 0 1
0 0 1 1 0
0 0 1 1 1
0 1 0 0 0
0 1 0 0 1
0 1 0 1 0
0 1 0 1 1
0 1 1 0 0
0 1 1 0 1
0 1 1 1 0
0 1 1 1 1
1 0 0 0 0
1 0 0 0 1
1 0 0 1 0
1 0 0 1 1
1 0 1 0 0
1 0 1 0 1
1 0 1 1 0
1 0 1 1 1
1 1 0 0 0
1 1 0 0 1
1 1 0 1 0
1 1 0 1 1
1 1 1 0 0
1 1 1 0 1
1 1 1 1 0
1 1 1 1 1
*/