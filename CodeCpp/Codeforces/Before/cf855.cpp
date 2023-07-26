#include<bits/stdc++.h>
using namespace std;

void solveA() {
    int n; cin >> n;
    string s; cin >> s;
    string meow = "MEOW";
    string ans = "yes";
    int j = 0;
    for (int i = 0; i < n; i++) {
        char x = toupper(s[i]);
        if (x == toupper(s[i + 1])) continue;
        if (x == meow[j] && j < 4) j++;
        else {ans = "no"; break;}
    }
    if (j != 4) ans = "no";
    cout << ans << "\n";
}

int cnt[256];

void solveB() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int ans = 0; int tmp;
    for (int i = 0; i < n; i++) {
        cnt[s[i]]++;
    }
    for (int c = 65; c <= 90; c++) {
        ans += min(cnt[c], cnt[c + 32]);
        tmp = abs(cnt[c] - cnt[c + 32]);
        while (tmp > 1 && k > 0) {
            ans++;
            tmp -= 2;
            k--;
        }
    }
    cout << ans << "\n";
}

void solveC1C2() {
    int n; cin >> n;
    long long ans = 0;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x != 0) pq.push(x);
        else if (!pq.empty()) {ans += pq.top(); pq.pop();};
    }
    cout << ans << endl;
}

void solveD() {
    int n; cin >> n;
    string s; cin >> s;
    s = " " + s + " ";
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        if (s[i] != s[i - 2]) ans++;
    }
    cout << ans  << endl;
}

void solveE1E2() {
    int n, k; cin >> n >> k;
    string s, t;
    cin >> s >> t;
    bool ok = true;
    vector<int> cnt(26, 0);
    for (int i = 0; i < n; i++) {
        if (k <= i || i < n - k) {
            cnt[s[i] - 'a']++;
            cnt[t[i] - 'a']--;
        } else
            if (s[i] != t[i]) ok = false;
    }
    if (ok && count(cnt.begin(), cnt.end(), 0) == 26) cout << "yes\n"; else cout << "no\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        solveE1E2();
    }
}
