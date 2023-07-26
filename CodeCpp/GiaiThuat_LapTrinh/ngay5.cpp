#include<bits/stdc++.h>
using namespace std;

struct doan
{
    int dau, cuoi, giatri;
};

bool cmpDoan(doan a, doan b)
{
    return (a.dau < b.dau || (a.dau == b.dau && a.cuoi <= b.cuoi));
}

void phuLenN()
{
    int n; cin >> n;
    vector<doan> d(n);
    for (int i = 0; i < n; i++)
    {
        int x, di; cin >> x >> di;
        d[i].dau = x;
        d[i].cuoi = x + di;
    }
    int s = 0;
    sort(d.begin(), d.end(), cmpDoan);
    int cur1 = 0, cur2 = 0;
    vector<doan> res;
    while (cur1 < n)
    {
        doan tmp;
        tmp.dau = d[cur1].dau;
        tmp.cuoi = d[cur1].cuoi;
        cur2 = cur1 + 1;
        while (cur2 < n && tmp.cuoi >= d[cur2].dau)
        {
            tmp.cuoi = d[cur2].cuoi;
            cur2++;
        }
        s += tmp.cuoi - tmp.dau;
        cur1 = cur2;
    }
    cout << s;
}

//---------------------------------------------------------------- 1

void maxPhuLen()
{
    int n; cin >> n;
    vector<doan> d(n);
    for (int i = 0; i < n; i++)
        cin >> d[i].dau >> d[i].cuoi;
    
    sort(d.begin(), d.end(), cmpDoan);
    int cur1 = 0, cur2 = 0;
    vector<doan> res;
    vector<int> c;
    while (cur1 < n)
    {
        doan tmp;
        tmp.dau = d[cur1].dau;
        cur2 = cur1 + 1;
        while(!c.empty() && d[cur1].dau >= c.back())
            c.pop_back();

        c.push_back(d[cur1].cuoi);

        if (d[cur1].cuoi <= d[cur2].dau)
            tmp.cuoi = d[cur1].cuoi;
        else
            tmp.cuoi = d[cur2].dau;
        tmp.giatri = c.size();
        res.push_back(tmp);
        cur1 = cur2;
    }
}

//  CHUA LAM
//---------------------------------------------------------------- 2

struct sumId
{
    int val, ind;
};

bool cmp2s(sumId a, sumId b)
{
    return (a.val < b.val || (a.val == b.val && a.ind <= b.ind));
}

void maxCon()
{
    int n; cin >> n;
    vector<sumId> a(n);
    vector<int> sto(n);
    int s = 0;
    for (int i = 0; i < n; i++)
    {  
        cin >> sto[i];
        s += sto[i];
        a[i].val = s;
        a[i].ind = i;
    }
    sort(a.begin(), a.end(), cmp2s);
    vector<int> b(n), c(n);

    for (int i = 0; i < n; i++)
    {
        b[i] = a[i].val;
        c[i] = a[i].ind;
    }

    int res = 0, resi = 0, resj = 0;
    for (int  i = 0; i < n; i++)
    {
        int tmp = lower_bound(b.begin(), b.end(), b[i]) - b.begin();
        if (c[i] - c[tmp] > res)
        {
            res = c[i] - c[tmp];
            resi = c[i];
            resj = c[tmp];
        }
    }
    if (res == 0)
    {
        cout << -1;
        return;
    }
    for (int i = resj + 1; i < resi; i++)
        cout << sto[i] << " ";
    cout <<  sto[resi] << endl;
}

//---------------------------------------------------------------- 3

struct _2stat
{
    int num;
    string str;
};

bool cmp2nts(_2stat a, _2stat b)
{
    return (a.str >= b.str);
}

void numJoin()
{
    int n; cin >> n;
    vector<_2stat> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].num;
        a[i].str = to_string(a[i].num);
        while (a[i].str.length() < 9) a[i].str.push_back(0);
    }
    sort(a.begin(), a.end(), cmp2nts);
    for (auto i : a)
        cout << i.num;
}

//---------------------------------------------------------------- 4

void eseq()
{
    int n; cin >> n;
    vector<sumId> a(n);
    vector<int> sto(n);
    int s = 0;
    for (int i = 0; i < n; i++)
    {  
        cin >> sto[i];
        s += sto[i];
        a[i].val = s;
        a[i].ind = i;
    }
    sort(a.begin(), a.end(), cmp2s);
    vector<int> b(n), c(n);
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i].val;
        c[i] = a[i].ind;
    }

    int res = 0;
    for (int  i = 0; i < n; i++)
    {
        int tmp1 = lower_bound(b.begin(), b.end(), b[n - 1] - b[i]) - b.begin(),
        tmp2 = upper_bound(b.begin(), b.end(), b[n - 1] - b[i]) - b.begin();
        if (tmp2 == b.end() - b.begin()) tmp2--;
        if (b[n - 1] - b[tmp1] == b[i])
        {
            while (c[tmp1] < c[i]) tmp1++;
            if (tmp2 >= tmp1) res += tmp2 - tmp1;
        }
    }
    cout << res;
}

//---------------------------------------------------------------- 5

int cntW[26], cntw[26], cntS[26], cnts[26];

void maia()
{
    int g, S;
    cin >> g >> S;
    string w, s;
    cin >> w >> s;
    for (int i = 0; i < g; i++)
    {   
        if (w[i] >= 'a')
            cntw[w[i] - 'a']++;
        else
            cntW[w[i] - 'A']++;
    }

    for (int i = 0; i < g - 1; i++)
        if (s[i] >= 'a')
            cnts[s[i] - 'a']++;
        else
            cntS[s[i] - 'A']++;

    int res;

    for (int i = g - 1; i < S - g + 1; i++)
    {
        bool ok = true;
        if (s[i] >= 'a')
            cnts[s[i] - 'a']++;
        else
            cntS[s[i] - 'A']++;
        for (int i = 0; i <= 26; i++)
            if (cntw[i] != cnts[i])
            {
                ok = false;
                break;
            }
        if (ok)
        for (int i = 0; i <= 26; i++)
            if (cntW[i] != cntS[i])
            {
                ok = false;
                break;
            }
        if (s[i - g + 1] >= 'a')
            cnts[s[i - g + 1] - 'a']--;
        else
            cntS[s[i - g + 1] - 'A']--;
        if (ok)
            res++;
    }
    cout << res;
}

//---------------------------------------------------------------- 6

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    maia();
}