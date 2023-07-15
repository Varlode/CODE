#include<bits/stdc++.h>
using namespace std;

void arran(int r, string& s) {
    if (r == 0) return;
    if (r % 2 == 0) {
        arran(r - 1, s);
        char tmp = s[0];
        for (int i = 1; i <= r; i++) s[i - 1] = s[i];
        s[r] = tmp;        
    } else {
        if (r > 1) {
            arran(r / 2, s);
            int cur1 = 0, cur2 = r / 2 + 1, cnt = 0, dd[r];
            for (int i = 0; i <= r; i++)
                if (i % 2 == 0) dd[cnt++] = s[cur2++];
                else dd[cnt++] = s[cur1++];
            for (int i = 0; i <= r; i++) s[i] = dd[i];
        } else {
            swap(s[0], s[1]);
        }
    }
}
int main() {
    string s; cin >> s;
    arran(s.size() - 1, s);
    cout << s;
    return 0;
}