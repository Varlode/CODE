#include<bits/stdc++.h>
using namespace std;

void smallestS()
{
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    if (a.size() % 2 == 0)
    {
        for (int i = a[a.size() / 2 - 1]; i < a[a.size() / 2]; i++)
            cout << i << " ";
        cout << a[a.size() / 2];
    } else
        cout << a[a.size() / 2];
}

//---------------------------------------------------------------- 1

void smallestDis()
{
    int n; cin >> n;
    vector<int> xi(n), yi(n);
    for (int i = 0; i < n; i++)
        cin >> xi[i] >> yi[i];
    sort(xi.begin(), xi.end());
    sort(yi.begin(), yi.end());
    cout << xi[n / 2] << " " << yi[n / 2];
}

//---------------------------------------------------------------- 2

struct toaDo
{
    int x, y;
};

bool xy[2002][2002];

void cntRec()
{
    int n; cin >> n;
    vector<toaDo> a(n);
    for (int i = 0; i < n; i++)
    {
        int x, y; cin >> x >> y;
        a[i].x = x; a[i].y = y;
        xy[x + 1000][y + 1000] = true;
    }
    int res = 0;
    for (int i = 0; i < n; i++)
        for (int ii = 0; ii < n; ii++) if (ii != i)
            for (int iii = 0; iii < n; iii++) if (iii != i && iii != ii)
            {
                int d_1_2, d_1_3, d_2_3;
                d_1_2 = abs(a[i].x - a[ii].x) * abs(a[i].x - a[ii].x)  + abs(a[i].y - a[ii].y) * abs(a[i].y - a[ii].y);
                d_1_3 = abs(a[i].x - a[iii].x) * abs(a[i].x - a[iii].x) + abs(a[i].y - a[iii].y) * abs(a[i].y - a[iii].y);
                d_2_3 = abs(a[ii].x - a[iii].x) * abs(a[ii].x - a[iii].x) + abs(a[ii].y - a[iii].y) * abs(a[ii].y - a[iii].y);
                if (d_1_2 + d_1_3 == d_2_3 && 
                xy[a[iii].x + a[ii].x - a[i].x + 1000][a[iii].y + a[ii].y - a[i].y + 1000])
                res++;
            }
    cout << int(res / 8);
}

//---------------------------------------------------------------- 3

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cntRec();
}