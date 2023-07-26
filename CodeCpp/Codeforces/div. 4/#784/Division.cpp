#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, rating;
    cin >> t;
    for (int i = 1; i <= t; i++) {
    	cin >> rating;
		int division = 4;
    	cout << "Division ";
    	if (rating > 1399) division--;
    	if (rating > 1599) division--;
    	if (rating > 1899) division--;
    	cout << division << endl;
	}
    return 0;
}
