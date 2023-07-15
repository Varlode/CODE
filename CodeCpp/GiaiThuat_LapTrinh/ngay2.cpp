#include <bits/stdc++.h>
#define i1e9 int(1e9)
using namespace std;

bool primes[1000000];

void primesListed() 
{
    memset(primes, 1, sizeof(primes));
    int l, r;
    cin >> l >> r;
    for (int i = 2; i <= sqrt(r); i++)
    {   
        if (!primes[i]) continue;
        for (int j = 2; j <= r / i; j++)
        {
            primes[i * j] = false;
        }
    }
    for (int i = l; i <= r; i++)
    {
        if (primes[i]) cout << i << "\n";
    }
}

//---------------------------------------------------------------- 1

void theLastsOfBigNum() 
{
    int k, m, n;
    cin >> k >> m >> n;
    long long tenth[] = {1, 10, 100, 
                        1000, 10000, 
                        100000, 1000000, 
                        10000000, 100000000,
                        1000000000};
    long long modM = 1;
    for (int i = 0; i < n; i++) {
        modM = (modM % tenth[k]) * (m % tenth[k]);
    }
    cout << modM << "\n";
}

//---------------------------------------------------------------- 2

void GCDsAndLCMs() 
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int gcds = arr[0], lcms = arr[0];
    for (int i = 0; i < n; i++)
    {
        gcds = __gcd(gcds, arr[i]);
        int tmp = __gcd(arr[i], lcms);
        lcms = (lcms * arr[i]) / tmp;
        lcms %= i1e9;
    }
    cout << gcds << "\t" << lcms << "\n";
}

//---------------------------------------------------------------- 3

string sum2string(string a, string b)
{   
    while (a.length() < b.length()) a = '0' + a;
    while (b.length() < a.length()) b = '0' + b;
    int n = a.size();
    int m = b.size();
    string c = "";
    int carry = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        carry = sum / 10;
        c = to_string(sum % 10) + c;
    }
    if (carry) c = to_string(carry) + c;
    return c;
}

bool cmp3(string s, string a)
{
    while (a.length() < s.length()) a = '0' + a;
    while (s.length() < a.length()) s = '0' + s;
    if (s >= a) return true;
    else return false;
}

bool cmp2(string s, string b)
{
    while (s.length() < b.length()) s = '0' + s;
    while (b.length() < s.length()) b = '0' + b;
    if (s <= b) return true;
    return false;
}

void fibInAB()
{
    string a, b;
    cin >> a >> b;
    string fib0 = "0", fib1 = "1", fibn = "0";
    long long cnt = 0;
    if (a == "0") cnt = 2;
    if (a == "1") cnt = 1;
    while (cmp2(fibn, b))
    {
        fibn = sum2string(fib0, fib1);
        fib0 = fib1;
        fib1 = fibn;
        if (cmp3(fibn, a) && cmp2(fibn, b)) cnt++;
    }
    cout << cnt << "\n";
}

//---------------------------------------------------------------- 4

void cvtNumber()
{
    int n, m; string s;
    cin >> n >> m >> s;
    int numCvt = 0, mem = 1;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] > '9')
            numCvt += mem * (s[i] + 10 - 'A');
        else
            numCvt += mem * (s[i] - '0');
        mem *= n;
    }
    
    string numCvted = "";
    while (numCvt > 0)
    {
        if (numCvt % m >= 10)
            numCvted = char((numCvt % m) - 10 + 'A') + numCvted;
        else
            numCvted = char((numCvt % m) + '0') + numCvted;
        numCvt /= m;
    }
    cout << numCvted << "\n";
}

//---------------------------------------------------------------- 5

string multi2string(string a, string b)
{
    while (a.length() < b.length()) a = '0' + a;
    while (b.length() < a.length()) b = '0' + b;
    int n = a.size();
    int m = b.size();
    string c = "";
    int carry = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int sum = (a[i] - '0') * (b[i] - '0') + carry;
        carry = sum / 10;
        c = to_string(sum % 10) + c;
    }
    if (carry) c = to_string(carry) + c;
    return c;
}

int unsig[101][101], sig[101][101];

void TGS()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++) {
            cin >> sig[i][j];
            unsig[i][j] = abs(sig[i][j]);
        }
    //KHONG BIET LAM
}

//---------------------------------------------------------------- 6

int jungle[110][110], j[3][110][110];
queue<int> dx, dy;

void path(int x, int y)
{
    j[1][x][y] = j[1][x-1][y] + j[1][x][y-1];
    j[2][x][y] = j[2][x-1][y] + j[2][x][y-1];
    j[3][x][y] = j[3][x-1][y] + j[3][x][y-1];
    j[jungle[x][y]][x][y]++;

    dx.push(x); dy.push(y + 1);
    dx.push(x + 1); dy.push(y);

    while ((!dx.empty()) && (!dy.empty())) 
    {
        int tmpx = dx.front(), tmpy = dy.front();
        dx.pop(); dy.pop();
        path(tmpx, tmpy);
    }
}

void mushRoom()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> jungle[i][j];
    path(0, 0);
    cout << min(j[1][m - 1][n], min(j[2][m - 1][n], j[3][m - 1][n]))
    +       min(j[1][m][n - 1], min(j[2][m][n - 1], j[3][m][n - 1])) << "\n";
    //KHONG BIET LAM
}

//---------------------------------------------------------------- 7

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    mushRoom();
}