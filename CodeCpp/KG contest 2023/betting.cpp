#include<bits/stdc++.h>
using namespace std;

int n;
double a, b;
const int N = 1e6;

vector<pair<double, int> > trump, biden;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        trump.push_back({a, i});
        biden.push_back({b, i});
    }
    sort(trump.begin(), trump.end(), greater<pair<double, int> >());
    sort(biden.begin(), biden.end(), greater<pair<double, int> >());

    double ans = 0;
    double sum_trump = 0, sum_biden = 0;
    int cnt_trump = 0, cnt_biden = 0;

    for (int i = 0; i < n; i++) {
        sum_biden = 0;
        cnt_biden = 0;
        cnt_trump++;
        sum_trump += trump[i].first;
        // for (int k = 0; k <= i; k++) cout << trump[k].first << ' '; cout << endl;
        for (int j = 0; j < n; j++) {
            // cout << biden[j].first << ' ';
            cnt_biden++;
            sum_biden += biden[j].first;
            ans = max(ans, min(sum_biden, sum_trump)-(cnt_trump+cnt_biden));
        }
        // cout << ans << endl;
    }

    cout << fixed << setprecision(4) << ans;
}