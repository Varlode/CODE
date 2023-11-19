#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;
int n, ans[N];
string s;

stack<int> op;

int main() {
    cin >> s;
    cout << s.size() << endl;
    // for (int i = 0; i < s.size(); i++) {
    //     char c = s[i];
    //     if (c == '(') {
    //        op.push(i);
    //     } else 
    //     if (c == ')') {
    //         if (op) {
    //             op--;
    //             cnt += 2;
    //             cout << 1;
    //         } else {
    //             ans[cnt]++;
    //             cnt = 0;
    //             cout << 0;
    //         }
    //     }
    // }
    // cout << endl;
    // ans[0] = 1;
    // for (int i = s.size(); i >= 0; i--) {
    //     // cout << ans[i] << ' ';
    //     if (ans[i]) {
    //         cout << i << ' ' << ans[i];
    //         break;
    //     }
    // }
}