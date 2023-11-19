#include<bits/stdc++.h>
using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        vector<char> odd, even, res;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] % 2 == 0) {
                even.push_back(s[i]);
            } else {
                odd.push_back(s[i]);
            }
        }

        if (odd.size() == 0 or even.size() == 0) {
            cout << s << endl;
            continue;
        }

        int i = 0, j = 0;
        while (i < odd.size() || j < even.size()) {
            if (i < odd.size() && (odd[i] < even[j] || j == even.size())) {
                cout << odd[i];
                i++;
            } else if (j < even.size()) {
                cout << even[j];
                j++;
            }
        }
        
        cout << endl;
    }
}