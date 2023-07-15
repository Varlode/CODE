#include<bits/stdc++.h>
using namespace std;

void bai1() {
    string s;
    cin >> s;
    if (s.size() == 0) return;
    string ss = s;
    reverse(s.begin(), s.end());
    int l1 = s.size(), l2 = ss.size();
    while (l1 < l2) {
        s = '0' + s;
        l1++;
    }
    while (l1 > l2) {
        ss = '0' + ss;
        l2++;
    }
    string res = " = ";
    for (int i = 0; i < l1; i++) {
        if (s[i] < ss[i]) {
            res = " < ";
            break;
        } else if (s[i] > ss[i]) {
            res = " > ";
            break;
        }
    }
    while(s[0] == '0') s.erase(s.begin());
    cout << s << res << ss << "\n";
}

void bai2() {
    long long n;
    cin >> n;
    long long tong1 = n*(n+1)/2 + (n/3)*3 + n%3*(n%3 + 1)/2;
    long long tong2 = n*(n+1)/2 + (n/2)*2 + n%2*2;
    if (tong1 > tong2) cout << "A " << tong1 - tong2;
    else if (tong1 < tong2) cout << "B " << tong2 - tong1;
    else cout << "C " << tong1;
}

void bai3() {
    vector<string> s;
    while (!feof(stdin)) {
        string ss;
        getline(cin, ss);
        if (ss.size() == 0) break;
        int i = 0;
        while (i < ss.size() - 1) {
            if (ss[i] == ss[i + 1] && ss[i] == ' ') ss.erase(ss.begin() + i);
            else i++;
        }
        ss[0] = toupper(ss[0]);
        for (i = 0; i < ss.size() - 1; i++) {
            if (ss[i] == ' ' & ss[i + 1] != ' ') ss[i + 1] = toupper(ss[i + 1]);
            else ss[i + 1] = tolower(ss[i + 1]);
        }
        while (ss[0] == ' ') ss.erase(ss.begin());
        while (ss[ss.size()-1] == ' ') ss.erase(ss.end() - 1);
        string Ho = "", Ten = "";
        i = ss.size() - 1;
        while(i >= 0) {
            if (ss[i] == ' ') break;
            Ten = ss[i] + Ten;
            i--;
        }
        i--;
        while(i >= 0) {
            Ho = ss[i] + Ho;
            i--;
        }
        s.push_back(Ten + ' ' + Ho);
    }
    sort(s.begin(), s.end());
    for (auto sss: s) {
        cout << sss << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    bai3();

}
