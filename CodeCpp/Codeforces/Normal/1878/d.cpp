#include<bits/stdc++.h>
using namespace std;

int a[300000];


int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        string str; cin >> str;

        

        vector<int> l(k), r(k);
        
        for (int i = 0; i < n; i++) a[i] = i;

        for (int i = 0; i < k; i++) {
            cin >> l[i];
        }
        for (int i = 0; i < k; i++) {
            cin >> r[i];
        }

        int q; cin >> q;

        vector<vector<int>> d(k);
        vector<int> x(q);
        
        for (int i = 0; i < q; i++) {
            cin >> x[i];
        }

        for (int i = 0; i < q; i++) {
            int tmp = upper_bound(l.begin(), l.end(), x[i]) - l.begin() - 1;
            cout << tmp << ' ';
            d[tmp].push_back(min(x[i], r[i]+l[i]-x[i]));
        }

        cout << endl;

        for (int i = 0; i < k; i++) {
            cout << i << ' ' << d[i].size() << endl;
            if (d[i].size() == 0) continue;
            sort(d[i].begin(), d[i].end());

            // cout << "pass sort" << endl;

            stack<int> s;
            for (int j = 0; j < d[i].size(); j++) 
                if (s.empty()) s.push(d[i][j]);
                else {
                    if (s.top() == d[i][j]) s.pop();
                    else s.push(d[i][j]);
                }

            // cout << "pass push" << endl;

            d[i].clear();
            while (s.size()) {
                d[i].push_back(s.top());
                s.pop();
            }

            // cout << "pass clear" << endl;

            for (int j = 0; j < d[i].size()-1; j++) {
                if (d[i][j] == d[i][j+1]) j += 2;
                else {
                    int mi1 = min(d[i][j], l[i]+r[i]-d[i][j]), ma1 = max(d[i][j], r[i]+l[i]-d[i][j]);
                    int mi2 = min(d[i][j+1], l[i]+r[i]-d[i][j+1]), ma2 = max(d[i][j+1], l[i]+r[i]-d[i][j+1]);
                    cout << mi1 << ' ' << ma1 << ' ' << mi2 << ' ' << ma2 << endl;
                    for (int ii = min(mi1, mi2), jj = max(ma1, ma2); ii <= max(mi1, mi2); ii++, jj--) {
                        swap(a[ii], a[jj]);
                    }
                }
            }
            
            // cout << "pass swap" << endl;
        }
        
        for (int i = 0; i < n; i++) {
            cout << str[a[i]];
        }
        cout << endl;
    }
}