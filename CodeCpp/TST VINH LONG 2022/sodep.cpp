#include<bits/stdc++.h>
using namespace std;

int snt[255], n, cnt = 0;
string a;

int process(string s) {
    int ans = 0;
    for (int i = 0; i < s.size(); i++) 
        ans += (s[i] - '0')*(s[i]-'0');
    return ans;
}

int main() {
    snt[0] = snt[1] = 1;
    for (int i = 2; i < 255; i++)
        for (int j = 2; i*j < 255; j++) 
            snt[i*j] = 1;
    cin >> n;
    while (n--) {
        cin >> a;
        if (snt[process(a)] == 0) cnt++;
    }
    cout << cnt << endl;
}