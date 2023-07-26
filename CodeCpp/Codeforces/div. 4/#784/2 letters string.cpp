#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t, n;
    long long res;
    string x;
    
    cin >> t;
    while (t--) {
		
    	vector<string> s;
    	map<char, int> count0, count1;
    	map<string, int> dup;
    	
    	res = 0;
    	cin >> n;
    	for (int i = 1; i <= n; i++) {
    		cin >> x;
			s.push_back(x);	
    	}
		for (int i = 0; i < s.size(); i++) {
			res += count0[s[i][0]] + count1[s[i][1]] - 2*dup[s[i]];
			count0[s[i][0]]++;
			count1[s[i][1]]++;
			dup[s[i]]++;
		}
		cout << res << endl;
	}
    return 0;
}
