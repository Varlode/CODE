#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	getline(cin ,s);
	int i = 0, count = 0;
	
	map<char, int> m;
	m['.'] = 1, m[','] = 1, m[' '] = 1;
	
	while (i < s.size()) {
		while (m[s[i]] and i < s.size()) i++;
		if (i == s.size()) break;
		count++;
		while (not m[s[i]] and i < s.size()) i++;
	}
	cout << count;
}
