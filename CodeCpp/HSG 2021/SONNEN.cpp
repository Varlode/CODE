#include<bits/stdc++.h>
using namespace std;

int n;
string s1, s2, sn;

string op(string a, string b) {
    string ans;
    int mem = 0;
    while (a.size() && b.size()) {
        ans.push_back(char((a.back()+b.back()-2*'0'+mem)%10+'0'));
        mem = (a.back()+b.back()-2*'0'+mem)/10;
        a.pop_back();
        b.pop_back();
    }
    while (a.size()) {
        ans.push_back(char((a.back()-'0'+mem)%10+'0'));
        mem = (a.back()-'0'+mem)/10;
        a.pop_back();
    }
    while (b.size()) {
        ans.push_back(char((b.back()-'0'+mem)%10+'0'));
        mem = (b.back()-'0'+mem)/10;
        b.pop_back();
    }
    if (mem == 1) ans.push_back('1');
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    cin >> n;
    s1 = s2 = '1';
    sn = '\0';
    if (n <= 2) {
        cout << 1;
        return 0;
    }
    for (int i = 3; i <= n; i++) {
        sn = op(s1, s2);
        s1 = s2;
        s2 = sn;
    }
    cout << sn;
}