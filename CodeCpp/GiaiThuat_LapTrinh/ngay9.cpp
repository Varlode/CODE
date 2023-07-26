#include<bits/stdc++.h>
using namespace std;

struct stct_cv
{
    int p, d, ind;
};

bool cmp(stct_cv a, stct_cv b)
{
    return (a.d < b.d || (a.d == b.d && a.p <= b.p));
}

vector<stct_cv> cv;
vector<int> resCV;
int nCV;

void _init()
{
    cin >> nCV;
    cv = vector<stct_cv>(nCV);
    for (int i = 0; i < nCV; i++)
        cin >> cv[i].p;
    for (int i = 0; i < nCV; i++)
        cin >> cv[i].d;
    for (int i = 0; i < nCV; i++)
        cv[i].ind = i;
}

void slav()
{
    _init();
    sort(cv.begin(), cv.end(), cmp);
    int time = 0;
    for (int i = 0; i < nCV; i++)
    {
        if (time + cv[i].p <= cv[i].d) {
            time += cv[i].p;
            resCV.push_back(cv[i].ind + 1);
        }
    }
    cout << resCV[0];
    for (int i = 1; i < resCV.size(); i++)
        cout << " " << resCV[i];
}

//---------------------------------------------------------------- 1

int a_luythua_n(int a, int n)
{
    if (a == 0 && n == 0) return -1;
    if (n == 0) return 1;
    if (n == 1) return a;
    int tmp = a_luythua_n(a, n / 2);
    if (n % 2) return (tmp*tmp*a);
    else return (tmp*tmp);
}

void calc_a_n()
{
    int a, n; cin >> a >> n;
    cout << a_luythua_n(a, n);
}

//---------------------------------------------------------------- 2

vector<int> a_diff;

void diff(int l, int r, int &dif, int &ma, int &mi)
{
    if (r == l)
    {
        ma = a_diff[r];
        mi = a_diff[r];
        dif = 0;
        return;
    }
    int ma0 = 0, mi0 = 0, dif0 = 0, dif1 = 0, ma1 = 0, mi1 = 0;
    diff(l, (r + l) / 2, dif0, ma0, mi0);
    diff((r + l) / 2 + 1, r, dif1, ma1, mi1);
    dif = max(max(dif0, dif1), ma1 - mi0);
    ma = max(ma1, ma0);
    mi = min(mi1, mi0);
}

void _pro_diff()
{
    int n; cin >> n;
    a_diff.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a_diff[i];
    int maD = 0, miD = 0, res = 0;
    diff(0, n - 1, res, maD, miD);
    cout << max(0, res);
}

//---------------------------------------------------------------- 2

int nen[1 << 10][1 << 10], cnt = 1;

void lat(int x, int y, int khuyet, int si)
{
    if (si == 1) 
    {
        if (khuyet != 1) nen[x][y] = cnt;
        if (khuyet != 2) nen[x][y + 1] = cnt;
        if (khuyet != 3) nen[x + 1][y] = cnt;
        if (khuyet != 4) nen[x + 1][y + 1] = cnt;
        cnt++;
        return;
    }
    si--;
    if (khuyet != 1) lat(x, y, 4, si); 
    else lat(x + (1 << (si - 1)), y + (1 << (si - 1)), 1, si);

    if (khuyet != 2) lat(x, y + (1 << si), 3, si);
    else lat(x + (1 << (si - 1)), y + (1 << (si - 1)), 2, si);

    if (khuyet != 3) lat(x + (1 << si), y, 2, si);
    else lat(x + (1 << (si - 1)), y + (1 << (si - 1)), 3, si);

    if (khuyet != 4) lat(x + (1 << si), y + (1 << si), 1, si);
    else lat(x + (1 << (si - 1)), y + (1 << (si - 1)), 4, si);
}

void lat_nen()
{
    int n; cin >> n;
    lat(0, 0, 2, n);
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < (1 << n); j++)
            cout << nen[i][j] << "\t";
        cout << endl;
    }
}

//---------------------------------------------------------------- 3

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    lat_nen();
}