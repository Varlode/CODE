#include<bits/stdc++.h>
using namespace std;

int main() {
    int test; cin >> test;
    while (test--) {
        queue<int> ans;
        int n; cin >> n;
        ans.push(9);
        if (9 % n == 0) {
            cout << 9;
            break;
        }
        while (ans.front() < 1e9) {
            cout << ans.front() << ' ';
            if (ans.front()*10 % n == 0) {
                cout << ans.front()*10;
                break;
            }
            else ans.push(ans.front()*10);
            if ((ans.front()*10+9) % n == 0) {
                cout << ans.front()*10+9;
                break;
            }
            else ans.push(ans.front()*10+9);
            ans.pop();
        }
        cout << endl;
    }
}