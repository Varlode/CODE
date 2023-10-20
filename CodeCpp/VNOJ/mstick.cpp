#include <bits/stdc++.h>

using namespace std;

struct wood {
    int l;
    int w;
};

bool cmp(wood a, wood b) {
    return (a.l < b.l || (a.l == b.l && a.w < b.w));
}

int main() {
	 ios_base::sync_with_stdio(false);
	 cin.tie(NULL);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<wood> a(n);
        
        for (int i = 0; i < n; i++)
            cin >> a[i].l >> a[i].w;

        sort(a.begin(), a.end(), cmp);
            
		vector<int> b(n);
		int count = 0; b[0] = a[0].w;
		for (int i = 1; i < n; i++) {
			if (a[i].w < b[count]) {
				count++;
				b[count] = a[i].w;
			}
			else {
				int tmp = 0;
				while (a[i].w < b[tmp] && tmp < count) tmp++;
				b[tmp] = a[i].w;
			}
		}
		
		cout << count + 1 << endl;
    }
}
