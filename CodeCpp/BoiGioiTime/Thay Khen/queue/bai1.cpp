#include<bits/stdc++.h>
using namespace std;

int main() {
    int test; cin >> test;
    while (test--) {
        queue<string> ans;
        int n; cin >> n; n--;
        ans.push("1");
        cout << 1 << ' ';
        while (n) {
            cout << ans.front()+"0" << ' '; n--;
            if (n == 0) break;
            cout << ans.front()+"1" << ' '; n--;
            
            ans.push(ans.front()+"0");
            ans.push(ans.front()+"1"); 
            ans.pop();
        }
        cout << endl;
    }
}