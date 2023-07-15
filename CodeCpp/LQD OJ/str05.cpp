#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin >> s;
    s = " " + s;
    for (int i = 1; i < s.size(); i++)
        if (s[i - 1] == " ") {if (s[i] >= "a") s[i] = s[i] - "a" + "A";}
        else if (s[i] > "A") s[i] = s[i] - "A" + "a";
    cout << s;
}
