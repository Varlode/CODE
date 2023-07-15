#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "w", stdout);
    cout << 100 << endl;
    srand(time(0));
    cout << rand() % (200000000 + 1);
    for (int i = 1; i < 1000; i++)
        cout << " " << rand() % (200000000 + 1);
}