#include<bits/stdc++.h>
using namespace std;

void cvtBinarytoHexa() {
    string s;
    cin >> s;

    //convert binary numbers to decimal numbers
    int bit = 1, dec = 0;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        dec += (s[i] - '0') * bit;
        bit *= 2;
    }

    //convert decimal numbers to hexa numbers
    string hex;
    while (dec > 0)
    {
        int rem = dec % 16;
        if (rem < 10)
            hex = (char)(rem + '0') + hex;
        else
            hex = (char)(rem + 'A' - 10) + hex;
        dec /= 16;
    }
    
    cout << hex << "\n";
}

//---------------------------------------------------------------- 1

void cvtNumber()
{
    int n;
    cin >> n;
    int tmp = n;
    vector<unsigned int> cntPrimes, primes;

    //Phan tich n thanh thua so nguyen to
    for (int i = 2; i < sqrt(n); i++)
    {
        if (tmp % i != 0) continue;
        int cnt = 0;
        while (tmp % i == 0)
        {
            cnt++;
            tmp /= i;            
        }
        cntPrimes.push_back(cnt);
        primes.push_back(i);
        cout << i << "\t" << cnt << "\n";
    }

    //Dem so uoc cua n
    int soUoc = 1;
    for (int i = 0; i < cntPrimes.size(); i++)
    {
        soUoc *= (cntPrimes[i] + 1);
    }
    cout << soUoc << "\n";

    //Tinh tong cac uoc cua n
    int tongUoc = 1;
    for (int i = 0; i < cntPrimes.size(); i++) 
    {
        tongUoc *= (pow(primes[i], cntPrimes[i] + 1) - 1) / (primes[i] - 1);
    }
    cout << tongUoc << "\n";
}

//---------------------------------------------------------------- 2

bool p[1000000];

void fermatPrimesAreWrong()
{
    memset(p, true, sizeof(p));
    for (int i = 2; i <= 1e3; i++)
        if (p[i] == true)
            for (int j = 2; j <= 1e6 / i; j++)
                p[i * j] = false;

    for (int n = 2; n <= 1e6; n++) 
    {   
        if (!p[n]) continue;
        //Tinh mod so fermat
        long long modN = 1;
        for (int i = 1; i <= n; i++) 
        {
            modN = (modN % n) * (2 % n);
            modN %= n;
        }
        
        bool fermatPrimes;

        if (modN == 2) fermatPrimes = true;
        else fermatPrimes = false;
        // if (fermatPrimes == true) cout << n << endl;
        if ((p[n] == true) != (fermatPrimes == true))
            cout << n << "\n";

    }
    cout << "OK\n";
    
}

//---------------------------------------------------------------- 3

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    fermatPrimesAreWrong();
}