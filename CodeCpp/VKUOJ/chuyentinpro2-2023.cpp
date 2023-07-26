#include<bits/stdc++.h>
using namespace std;

string m[10];
int mx[10][10], my[10][10];

int main() {
    m[0] = "2222222222";
    m[9] = "2222222222";
    memset(mx, 1, sizeof(mx));
    memset(my, 1, sizeof(my));
    for (int i = 1; i <= 8; i++) {
            cin >> m[i];
            m[i] = '2' + m[i] + '2';
        }
    int ans = 0;
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++) {
            if (m[i][j - 1] == m[i][j]) my[i][j] += my[i][j - 1];
            if (m[i - 1][j] == m[i][j]) mx[i][j] += mx[i - 1][j];
            ans = max(ans, max(my[i][j], mx[i][j]));
        }
    cout << ans;
}
