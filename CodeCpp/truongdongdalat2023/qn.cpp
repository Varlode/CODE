#include<bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()

vector<int> go(int n){
    if(n == 1) return {0, 1};

    vector<int> ans;
    vector<int> v = go(n- 1);

    for(auto x: v) ans.push_back(x);
    reverse(all(v));
    for(auto x: v) ans.push_back((1<<(n-1))+x);
    return ans;
}

void solve(){
    int n, k; cin >> n >> k;
    vector<int> ans = go(n);

    for(int i = 0; i < ans.size(); i++) {
        if(ans[i] == k) {
            for(int j = i+1; j < ans.size(); j++) cout << ans[j] << '\n';
            for(int j = 0; j <= i-1; j++) cout << ans[j] << '\n';
        }
    }

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "TASK"
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    solve();
}