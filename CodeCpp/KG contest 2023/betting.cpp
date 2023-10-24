#include<bits/stdc++.h>
using namespace std;

int n;
double a, b;
const int N = 1e6;

vector<double> trump, biden;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        trump.push_back(a-1);
        biden.push_back(b-1);
    }
    sort(trump.begin(), trump.end(), greater<double>());
    sort(biden.begin(), biden.end(), greater<double>());
    // cout << endl;
    // cout << trump[0] << ' ' << biden[0] << endl;
    for (int i = 1; i < n; i++) {
        trump[i] += trump[i-1];
        biden[i] += biden[i-1];
        // cout << trump[i] << ' ' << biden[i] << endl;
    }
    // cout << endl;

    double ans = max(0.0, min(trump[0], biden[0]) - 2.0);
    for (int i = 0; i < n; i++) {
        if (trump[i] < 1) continue;
        if (trump[i] > n) {
            ans = max(ans, min(trump[i]-n, biden[n-1]-(i+1)));
            continue;
        }
        // cout << trump[i]-(floor(trump[i])) << ' ' << biden[floor(trump[i])-1]-(i+1) << endl;
        ans = max(ans, min(trump[i]-(floor(trump[i])), biden[floor(trump[i])-1]-(i+1)));
    }
    // cout << endl;
    cout << fixed << setprecision(4) << ans;
}