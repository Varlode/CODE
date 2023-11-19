#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define TASK "mixmilk"
    if (fopen(TASK".in", "r")) {
        freopen(TASK".in", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int bucket[3], cap[3];
    cin >> cap[0] >> bucket[0];
    cin >> cap[1] >> bucket[1];
    cin >> cap[2] >> bucket[2];
    int n = 100;
    int flag = 0;
    while (n--) {
        if (flag == 0) {
            if (bucket[0] + bucket[1] <= cap[1]) {
                bucket[1] += bucket[0];
                bucket[0] = 0;
            } else {
                bucket[0] -= (cap[1] - bucket[1]);
                bucket[1] = cap[1];
            }
        }
        else if (flag == 1) {
            if (bucket[1] + bucket[2] <= cap[2]) {
                bucket[2] += bucket[1];
                bucket[1] = 0;
            } else {
                bucket[1] -= (cap[2] - bucket[2]);
                bucket[2] = cap[2];
            }
        }
        else if (flag == 2) {
            if (bucket[2] + bucket[0] <= cap[0]) {
                bucket[0] += bucket[2];
                bucket[2] = 0;
            } else {
                bucket[2] -= (cap[0] - bucket[0]);
                bucket[0] = cap[0];
            }
        }
        flag += 1; flag %= 3;
    }
    cout << bucket[0] << '\n' << bucket[1] << '\n' << bucket[2];
}