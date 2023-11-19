#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t, n;
    int res;
    int x;
    
    cin >> t;
    while (t--) {
    	
    	int suml = 0, sumr = 0;
    	vector<int> s;
    	
    	s.clear();
    	res = 0;
    	cin >> n;
    	for (int i = 0; i < n; i++) {
    		cin >> x;
			s.push_back(x);	
    	}
    	int i = 0, j = s.size() - 1;
    	while (i < j) {
    		if (suml + s[i] < sumr + s[j]) {
				suml += s[i];
    			if (suml == sumr) res = i + 1 + s.size() - j;
    			i++;
			} else if (suml + s[i] > sumr + s[j]) {
				sumr += s[j];
				if (suml == sumr) res = i + 1 + s.size() - j;
				j--;
			} else {
				suml += s[i];
				sumr += s[j];
				res = i + 1 + s.size() - j;
				i++;
				j--;
			}
		}
		cout << res << endl;
	}
    return 0;
}
