#include<bits/stdc++.h>
using namespace std;

const int maxN=1e6;
string s[3];
int sum[3];
int flag[maxN], plus_5[maxN];

void print(string tmp) {
    int j = 0;
    while (tmp[j] == '0') j++;
    for (; j < tmp.size(); j++) {
        cout << tmp[j];
    }
}

int main() {
    cin >> s[0];
    int n = s[0].size();
    flag[n] = 1;
    for (int i = n-1; i >= 0; i--) {
        if ((s[0][i]-'0')%2==0) {
            s[1] = char((s[0][i]-'0')/2+48)+s[1];
            s[2] = char((s[0][i]-'0')/2+48)+s[2];
            flag[i] = flag[i+1];
            continue;
        }
        if (sum[1] == sum[2]) {
            s[1] = char((s[0][i]-'0')/2+1+48)+s[1];
            s[2] = char((s[0][i]-'0')/2+48)+s[2];
            sum[1]++;
            flag[i] = 1;
            continue;
        }
        if (sum[2] < sum[1]) {
            s[1] = char((s[0][i]-'0')/2+48)+s[1];
            s[2] = char((s[0][i]-'0')/2+1+48)+s[2];
            sum[2]++;
            flag[i] = 2;
            continue;
        }      
    }

    if (sum[1] == sum[2]) {
        cout << "YES" << endl;
        print(s[1]); cout << ' '; print(s[2]);
        return 0;
    }
    
    int i = 0;
    while ((sum[1] != sum[2] || plus_5[i]) && i < n) {
        if (s[0][i] == '9' && plus_5[i]) {
            s[1][i] = s[2][i] = '9';
            sum[flag[i]]--;
            plus_5[i+1] = 1;
            i++;
            continue;
        }
        if (plus_5[i]) {
            s[1][i] += 5;
            s[2][i] += 5;
        }
        if (s[0][i]%2!=0) {
            if (sum[1] != sum[2]) {
                sum[flag[i]]--;
                s[flag[i]][i]--;
                plus_5[i+1]++;
            }
            i++;
            continue;
        }
        if (s[0][i]%2==0) {
            if (sum[1] != sum[2]) {
                sum[3-flag[i]]--;
                s[3-flag[i]][i]--;
                plus_5[i+1]++;
            }
            i++;
            continue;
        }
    }
    if (plus_5[n]) cout << "NO" << endl;
    else cout << "YES\n"; print(s[1]); cout << ' '; print(s[2]);
}