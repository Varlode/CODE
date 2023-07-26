#include<bits/stdc++.h>
using namespace std;

int main() {
	string x;
	cin >> x;
	string y(x.size(), x[0]);
	
	if (x < y) {
		cout << y;
		exit(0);
	}
	
	if (x == y) {
		if (x[0] == '9') {
			x.replace(0, x.size(), x.size(), '1');
			cout << '1' + x;
			exit(0);
		}	
	}
	for (int i = 0; i < x.size(); i++){
		y[i] += 1;
	}
	cout << y;
}
