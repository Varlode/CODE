#include<bits/stdc++.h>
using namespace std;

int dp[200], A[200];
int N, K;

int main() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> A[i];
    deque<int> dq;
    int ans = 0;
    dq.push_back(0);
    for (int i = 1; i <= N + 1; ++i) {
        while (dq.size() && dq.front() < i - K) dq.pop_front();
        cout << dq.front() << ' ';
        dp[i] = dp[dq.front()] + A[i];
        ans += A[i];
        while (dq.size() && dp[dq.back()] >= dp[i]) dq.pop_back();
        dq.push_back(i);
    }
    cout << endl;
    for (int i = 1; i <= N + 1; i++) cout << dp[i] << ' ';
    cout << endl;
    cout << ans - dp[N + 1] << '\n';
}