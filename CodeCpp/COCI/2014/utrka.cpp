#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;
int n; 
map<string, int> m;
string s[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        m[s[i]]++;
    }
    for (int i = 1; i < n; i++) {
        string ss; cin >> ss;
        m[ss]--;
    }
    for (int i = 1; i <= n; i++) {
        if (m[s[i]] == 0) continue;
        cout << s[i];
        return 0;
    }
}