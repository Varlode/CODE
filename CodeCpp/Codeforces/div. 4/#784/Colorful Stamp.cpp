#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t, n;
    string res;
    char x;
    
    cin >> t;
    while (t--) {
    	cin >> n;
    	res = "";
    	int red = 0, blue = 0;
    	for (int i = 1; i <= n; i++) {
    		cin >> x;
    		if (x == 'W') {
    			if ((red > 0) xor (blue >0)) res = "no";
    			red = 0;
    			blue = 0;
			} else {
				if (x == 'R') red++;
				if (x == 'B') blue++;	
			}
		}
		if ((red > 0) xor (blue >0)) res = "no";
		if (res != "no") res = "yes";
		cout << res << endl;
	}
    return 0;
}
