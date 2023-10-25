#include<bits/stdc++.h>
using namespace std;

string s;

int minAB, minBA;

int main() {
    cin >> s;
    for (int i = 1; i < s.size(); i++) {
        if (s[i-1] == 'A' && s[i] == 'B') {
            if (minAB == 0) minAB = i;
            if (minBA && i-1 != minBA) {
                cout << "YES";
                return 0;
            }
        }
        else if (s[i-1] == 'B' && s[i] == 'A') {
            if (minBA == 0) minBA = i;
            if (minAB && i-1 != minAB) {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
}