#include<bits/stdc++.h>
using namespace std;

string c[27] = {
    "2", "22", "222", "3", "33", "333", "4", "44", "444", 
    "5", "55", "555", "6", "66", "666", "7", "77", "777", "7777",
    "8", "88", "888", "9", "99", "999", "9999"
};
map<int, int> m;

int main() {
    for (int i = 1; i <= 9; i++) {
        int a; cin >> a;
        m[a] = i;
    }
    string s; cin >> s;
    string p;
    for (char a: s) {
        if (c[a-'a'][0] == p[0]) cout << '#';
        for (char b: c[a-'a']) cout << m[b-'0'];
        p = c[a-'a'];
    }
}