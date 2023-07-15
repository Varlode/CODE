#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> s;
vector<bool> m;
	
void lietke(int i){
	if (s.size() == n){
		for(int j = 0; j < n; j++){
			cout << s[j];
		}
		cout << endl;
	} else for(int j = 0; j < n; j++){
		if (m[j]){
			m[j] = false;
			s.push_back(j + 1);
			lietke(i + 1);
			s.pop_back();
			m[j] = true;
		}
	}
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		m.push_back(true);
	}
	lietke(0);
}
