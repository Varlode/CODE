#include<bits/stdc++.h>
using namespace std;

int n;
string s, a;

void sinh(int i){
	if(i == n){
		cout << s << endl;
	} else for(int j = 0; j <= 1; j++){
		s[i] = a[j];
		sinh(i + 1);
	}
}

int main(){
	a = "01";
	cin >> n;
	for(int i = 1; i <= n; i++){
		s = s + "0";
	}
	sinh(0);
}
