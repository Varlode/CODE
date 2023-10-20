#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "w", stdout);
    srand(time(NULL));
    int n = rand() % 10 + 1;
    cout << n << endl;
    for (int i = 0; i < n; i++) cout << rand() % 10 + 1 - (rand() % 10 + 1) << " ";
    cout << endl;
    for (int i = 0; i < n; i++) cout << rand() % 10 + 1 - (rand() % 10 + 1) << " ";
}