#include<bits/stdc++.h>
using namespace std;

int size_int(long long n) {
    int ans = 0;
    while(n > 0) {
        n /= 10;
        ans++;
    }
    return ans;
}

int main() {
    int n_test; cin >> n_test;
    while (n_test--) {
        int n; cin >> n;
        queue<long long> q;
        vector<long long> ans;
        q.push(6); q.push(8);
        ans.push_back(6); ans.push_back(8);
        while (size_int(q.front()) < n) {
            ans.push_back(q.front()*10+6);
            ans.push_back(q.front()*10+8);
            q.push(q.front()*10+6);
            q.push(q.front()*10+8);
            q.pop();
        }
        sort(ans.begin(), ans.end(), greater<long long>());
        for (auto s: ans) {
            cout << s << ' ';
        }
        cout << endl;
    }
}