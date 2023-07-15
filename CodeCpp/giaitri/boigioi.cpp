#include<iostream>
#include<string>
#include<math.h>
using namespace std;

string sum2s(string a, string b) {
	long tmp1 = a.size(), tmp2 = b.size();
	string tmp(abs(tmp1 - tmp2), '0');
	(tmp1 < tmp2)? a = tmp + a : b = tmp + b;
	
	string res;
	int mem = 0, sum;
	
	for (long j = a.size() - 1; j >= 0; j--) {
		sum = (a[j] + b[j] - 96 + mem);
		res = char(sum % 10 + 48) + res;
		(sum >= 10)? mem = 1 : mem = 0;
	}
	if (mem != 0) return ("1" + res);
	return res;
}

int main() {
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
    int n;
    string f0, f1 ,fn;
    f0 = "0";
    f1 = "1";
    cin >> n;
    for (int i = 2; i <= n; i++) {
        fn = sum2s(f0, f1);
        f0 = f1;
        f1 = fn;
    }
    cout << fn;
}


