#include<bits/stdc++.h>
using namespace std;

int main() {
    unsigned a;
    cin >> a;
    bitset<8> s(a);
    vector<int> ans;
    for (int i = 0; i < s.size(); i++) if (s[i]) ans.push_back(i);

    cout << ans[0]; for (int i = 1; i < ans.size(); i++) cout << " " << ans[i];
}