#include<bits/stdc++.h>
using namespace std;

char st, en;
long double a[256][256], t;

int main() {
    freopen("thangnhiet.inp", "r", stdin);
    freopen("thangnhiet.out", "w", stdout);
    cin >> st >> t >> en;
    a['C']['F'] = t*1.8+32; a['C']['K'] = (a['C']['F']+459.67)/1.8;
    a['F']['C'] = (t-32)/1.8; a['F']['K'] = (t+459.67)/1.8;
    a['K']['F'] = t*1.8-459.67; a['K']['C'] =  (a['K']['F']-32)/1.8;
    cout << fixed << setprecision(2) << a[st][en] << endl;
}