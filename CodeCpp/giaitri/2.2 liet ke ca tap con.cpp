#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<int> s;

void lietke(int i, int x){
	if (i == k){
		for(int j = 0; j < k; j++){
			cout << s[j];
		}
		cout << endl;
	} else for(int j = x + 1; j <= n; j++){
		s[i] = j;
		lietke(i + 1, s[i]);
	}
}
int main(){
	cin >> n >> k;
	for(int i = 0; i < k; i++){
		s.push_back(0);
	}
	lietke(0, 0);
}
