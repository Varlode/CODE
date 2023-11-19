#include<bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;
long long sum, ans;
int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        pq.push(a);
        sum += a;
    }
    ans += sum;
    while (pq.size() > 1) {
        ans += sum;
        sum -= pq.top();
        pq.pop();
    }
    cout << ans;
}