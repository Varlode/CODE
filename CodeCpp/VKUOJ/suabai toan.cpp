#include<bits/stdc++.h>
using namespace std;
int s[7];
bool wasItSeen[10][10][10][10][10][10][10];

bool check() {
    int cnt[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    if (wasItSeen[s[0]][s[1]][s[2]][s[3]][s[4]][s[5]][s[6]] == true) return false;
    wasItSeen[s[0]][s[1]][s[2]][s[3]][s[4]][s[5]][s[6]] = true;
    if (s[0] == 0) return false;
    for (int i = 1; i < 7; i++)
        if (s[i] == s[i - 1]) return false;
    for (int i = 0; i < 7; i++)
        cnt[s[i]]++;
    if (cnt[0] != 2) return false;
    for (int i = 1; i < 10; i++)
        if (cnt[i] > 1) return false;
    return true;
}

int main1() {
    int ans = 0;
    for (int i1 = 0; i1 < 10; i1++)
    for (int i2 = 0; i2 < 10; i2++)
    for (int i3 = 0; i3 < 10; i3++)
    for (int i4 = 0; i4 < 10; i4++)
    for (int i5 = 0; i5 < 10; i5++)
    for (int i6 = 0; i6 < 10; i6++)
    for (int i7 = 0; i7 < 10; i7++) {
        s[0] = i1; s[1] = i2; s[2] = i3; s[3] = i4; s[4] = i5; s[5] = i6; s[6] = i7;
        if (check()) ans++;
    }
    cout << ans;
}
int cnt[10];
int main() {
    int64_t s;
    for (int i1 = 1; i1 <= 5; i1++) {
        cnt[i1] = true;
        for (int i2 = 0; i2 <= 5; i2++) if (!cnt[i2]) {
            cnt[i2] = true;
            for (int i3 = 0; i3 <= 5; i3++) if (!cnt[i3]) {
                cnt[i3] = true;
                for (int i4 = 0; i4 <= 5; i4++) if (!cnt[i4]) {
                    cnt[i4] = true;
                    for (int i5 = 0; i5 <= 5; i5++) if (!cnt[i5]) {
                        cnt[i5] = true;
                        for (int i6 = 0; i6 <= 5; i6++) if (!cnt[i6]) {
                            s += i1*100000+i2*10000+i3*1000+i4*100+i5*10+i6;
                        }
                        cnt[i5] = false;
                    }
                    cnt[i4] = false;
                }
                cnt[i3] = false;
            }
            cnt[i2] = false;
        }
        cnt[i1] = false;
    }
    cout << s;
}
