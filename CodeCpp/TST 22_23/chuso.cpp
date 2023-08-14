#include<bits/stdc++.h>
using namespace std;

string a, b;
int mem, m, freq, cnt[10];

int main() {
    cin >> a >> b;
    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 && j >= 0) {
        cnt[(a[i] + b[j] - 2*'0' + mem)%10]++;
        mem = (a[i] + b[j] - 2*'0' + mem)/10;
        i--; j--;
    }
    while (i >= 0) {
        cnt[(a[i] - '0' + mem)%10]++;
        mem = (a[i] - '0' + mem)/10;
        i--;
    }
    while (j >= 0) {
        cnt[(b[j] - '0' + mem)%10]++;
        mem = (b[j] - '0' + mem)/10;
        j--;
    }
    for (int i = 0; i < 10; i++) {
        if (cnt[i] >= freq) {
            freq = cnt[i];
            m = i; 
        }
    }
    cout << m << endl << freq;
}