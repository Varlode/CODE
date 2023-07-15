#include<bits/stdc++.h>
using namespace std;

int main(){
	string s = "0000000000000000000000000000000000000000000000000000000000000000000000000000000";
	string ss;
	while(true){
		system("cls");
		ss.erase();
		for(int j = 1; j <= 24; j++){
			for(int i = 0; i < s.size(); i++){	
				int random = rand() % 2;
				s[i] = random + 48;
			}
			ss = s + "\n";
		}
		cout << ss;
	}
}
