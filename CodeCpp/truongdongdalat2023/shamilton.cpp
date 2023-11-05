#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int n, current[N];
vector<string> str;
string str1, str2;
int deolamnua;
vector<int> v;
bool find() {
    if (v.size() == n) {
        str1 = str[v.back()]; str2 = str[v.front()];
        deolamnua = str1.back() == str2.front();
        return str1.back() == str2.front();
    }
    for (int i = 0; i < n; i++) {
        if (deolamnua) return true;
        if (v.size()) str1 = str[v.back()]; str2 = str[i];
        if (!current[i] && (v.empty() || str1.back() == str2.front())) {
            current[i] = true;
            v.push_back(i);
            if (!deolamnua && find()) {
                deolamnua = true;
                return true;
            }
            current[i] = false;
            v.pop_back();
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);

    cin >> n;
    // if (n > 20) {
    //     cout << -1 << endl;
    //     return 0;
    // }
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        str.push_back(s);
    }
    if (find()) for (int i : v) cout << i + 1 << " ";
    else cout << -1;
  
    return 0;
}
