#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;

int a[N], n, t, ans;
vector<int> mi;
deque<int> s;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;

        for (int i = 1; i <= n; i++) cin >> a[i];
        
        ans = 0;
        // tim max tu trai qua phai

        s.clear();
        mi.clear();

        for (int i = n; i >= 1; i--) {
            while (mi.size() && a[i] <= a[mi.back()]) mi.pop_back();
            while (s.size() && a[i] > a[s.back()]) s.pop_back();
            while (mi.size() && s.size() && mi.back() < s.front()) s.pop_front();

            ans += s.size();

            mi.push_back(i);
            s.push_back(i);
        }
        
        // tim max tu phai qua trai
        
        s.clear();
        mi.clear();

        for (int i = 1; i <= n; i++) {
            while (mi.size() && a[i] <= a[mi.back()]) mi.pop_back();
            while (s.size() && a[i] > a[s.back()]) s.pop_back();
            while (mi.size() && s.size() && mi.back() > s.front()) s.pop_front();

            ans += s.size();

            mi.push_back(i);
            s.push_back(i);
        }

        cout << ans+n << endl;
    }
}