#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    
    int tmp, s = 0, cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> tmp;
            if (i == j && tmp % 10 == 0) s += tmp;
        }
    cout << s;

}