#include <bits/stdc++.h>
using namespace std;

bool isNum(char c) {return '0' <= c && c <= '9';}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;

        vector<string> vs;
        string tmp; tmp.push_back(s[0]);
        for (int i = 1; i < s.size(); i++) 
            if (isNum(s[i]) == isNum(s[i-1])) tmp = tmp+s[i];
            else {
                vs.push_back(tmp);
                tmp = s[i];
            }
        vs.push_back(tmp);
        
        // for (string i: vs) cout << i << ' '; cout << endl;
        if (vs.size() == 4) {
            int n = stoi(vs[3]);
            string C;
            while (n > 0) {
                int k = n%26; k--;
                if (k == '@'-'A') k = 'Z'-'A';
                C = C+char(k+'A');
                n /= 26;
                if (k == 'Z' - 'A') n -= 1;
            }
            reverse(C.begin(), C.end());
            cout << C << vs[1] << endl;
        } else {
            string C = vs[0];
            reverse(C.begin(), C.end());
            int mem = 1, sum = 0;
            for (char c: C) {
                sum += (c-'A'+1)*mem;
                mem *= 26;
            }
            cout << 'R' << vs[1] << 'C' << sum << endl;
        }
    }   
}