#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n, a;
ll s;

priority_queue<int> hold, closed;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        int b = (hold.empty()? -1e9: hold.top());
        int c = (closed.empty()? -1e9: closed.top());

        if (b >= c) {
            if (b > a) {
                s += b-a;
                hold.pop();
                closed.push(a);
            } else {
                hold.push(a);
            }
        } else {
            if (c > a) {
                s += c-a;
                closed.pop();
                hold.push(c);
                closed.push(a);
            } else {
                hold.push(a);
            }
        }
    }
    cout << s;
}