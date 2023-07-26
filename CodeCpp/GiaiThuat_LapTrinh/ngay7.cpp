#include<bits/stdc++.h>
using namespace std;

void playWthN()
{
    int n, c, res = INT_MAX;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];
        sort(b.begin(), b.end());
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        int tmp1 = lower_bound(b.begin(), b.end(), -c) - b.begin();
        res = min(res, abs(c + b[tmp1]));
        if (tmp1 > 0) res = min(res, abs(c + b[tmp1 - 1]));
    }
    cout << res;
}

//---------------------------------------------------------------- 1

void daySo()
{
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int res = 0;
    int cnt = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {  
        cnt++;
        bool stb = false; 
        // cout << " i " << i << endl;
        for (int j = 0; j <= i; j++)
        {
            cnt++;
            // cout << " j " << j << endl;
            int f2 = upper_bound(a.begin() + j, a.end(), (int) (3 * a[i] - a[j]) / 2) - a.begin();
            for (int k = j + 1; k < f2; k++)
            {
                cnt++;
                if (find(a.begin() + k + 1, a.end(), 3 * a[i] - a[j] - a[k]) != a.end())
                    stb = true;
            }
            cnt--;
        }
        cnt--;
        if (stb) res++;
    }
    cout << cnt << endl;
    cout << res;
}

//CHUA LAM XONG
//---------------------------------------------------------------- 2

vector<int> res;
int n, k;

void printVecRes()
{
    cout << res[0];
    for (int i = 1; i < res.size(); i++)
        cout << " " << res[i];
    cout << endl;
}

void tH(int so, int n, int chap)
{
    if (chap == 0)
    {
        printVecRes();
        return;
    }
    if (n < so) return;
    for (int i = so; i <= n; i++)
    {
        res.push_back(i);
        tH(i + 1, n, chap - 1);
        res.pop_back();
    }
}

void toHop()
{
    cin >> n >> k;
    tH(1, n, k);
}

//---------------------------------------------------------------- 3

void CHL(int n, int chap)
{
    if (chap == 0)
    {
        printVecRes();
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        res.push_back(i);
        CHL(n, chap - 1);
        res.pop_back();
    }
}

void chinhHopLap()
{
    int n, k; cin >> n >> k;
    CHL(n, k);
}

//---------------------------------------------------------------- 4

bool daCo[10000000];
void CHKL(int n, int chap)
{
    if (chap == 0)
    {
        printVecRes();
        return;
    }
    for (int i = 1; i <= n; i++) if (daCo[i] == false)
    {
        daCo[i] = 1;
        res.push_back(i);
        CHKL(n, chap - 1);
        res.pop_back();
        daCo[i] = 0;
    }
}

void chinhHopKhongLap()
{
    cin >> n >> k;
    CHKL(n, k);
}

//---------------------------------------------------------------- 4

int cheoTr[16], cheoPh[16], cot[9], hang[9];

void printQH()
{
    cout << cot[1];
    for (int i = 2; i <= 8; i++) cout << " " << cot[i];
    cout << endl; 
}

void xepHau(int soCot)
{
    for (int soHang = 1; soHang <= 8; soHang++)
        if ((hang[soHang] == 0) && (cheoTr[8-soCot+soHang] == 0) && (cheoPh[soCot+soHang-1] == 0))
        {
            cot[soCot] = soHang;
            hang[soHang] = soCot;
            cheoTr[8-soCot+soHang] = soCot+soHang-1;
            cheoPh[soCot+soHang-1] = 8-soCot+soHang;
            if (soCot == 8) printQH();
            else xepHau(soCot + 1);
            hang[soHang] = 0;
            cheoTr[8-soCot+soHang] = 0;
            cheoPh[soCot+soHang-1] = 0;
        }
}

void _8quanHau()
{
    memset(hang, 0, sizeof(hang));
    memset(cot, 0, sizeof(cot));
    memset(cheoPh, 0, sizeof(cheoPh));
    memset(cheoTr, 0, sizeof(cheoTr));
    xepHau(1);
}

//---------------------------------------------------------------- 5

int S;
vector<int> a(20);

void chon(int soTo, int tongTien)
{   
    if (tongTien == S) printVecRes();
    if (soTo == n || tongTien > S) return;
    res.push_back(a[soTo]);
    chon(soTo + 1, tongTien + a[soTo]);
    res.pop_back();
    chon(soTo + 1, tongTien);
}

void _ATM()
{
    cin >> n >> S;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    chon(0, 0);
}

//---------------------------------------------------------------- 5

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    _ATM();
}