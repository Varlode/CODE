#include<bits/stdc++.h>
using namespace std;

int edges[21][21], visited[21], trip[21], ans[21];
int res = 1e9 + 7, cnt = 1, nOfCity, s = 0;

void traverse(int from)
{
    if (s >= res) return;

    trip[cnt - 1] = from;

    if (cnt == nOfCity && res > s + edges[from][0])
    {
        res = s + edges[from][0];
        for (int i = 0; i < nOfCity; i++)
            ans[i] = trip[i];
        return;
    }

    visited[from] = 1;
    
    for (int to = 1; to < nOfCity; to++)
    if (!visited[to])
    {
        cnt++;
        s += edges[from][to];
        traverse(to);
        s -= edges[from][to];
        cnt--;
    }

    visited[from] = 0;
    
}

void NguoiDiDuLich()
{
    cin >> nOfCity;
    for (int i = 0; i < nOfCity; i++)
        for (int j = 0; j < nOfCity; j++)
            cin >> edges[i][j];
    traverse(0);
    for (int i = 0; i < nOfCity; i++)
        cout << ans[i] + 1 << "->";
    cout << "1" << endl;
    cout << res;
}

//---------------------------------------------------------------- 1

class _ATM
{
private:
    int n, S, minSoTo, tongTien;
    vector<int> a, res;

    void _init()
    {
        cin >> n >> S;
        minSoTo = 1e9 + 7;
        tongTien = 0;
        a = vector<int>(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end(), greater<int>());
    }

    void print()
    {
        cout << minSoTo << endl;
        cout << ans[0];
        for (int i = 1; i < minSoTo; i++)
        cout << " " << ans[i];
        cout << endl;
    }

    void chon(int soTo)
    {   
        if (S > tongTien + a[soTo] * (n - soTo)) return;
        if (soTo == n || tongTien > S) return;
        if (tongTien == S && res.size() < minSoTo) 
        {
            minSoTo = res.size();
            for (int i = 0; i < res.size(); i++)
                ans[i] = res[i];
        }
        res.push_back(a[soTo]);
        tongTien = tongTien + a[soTo];
        chon(soTo + 1);
        tongTien = tongTien - a[soTo];
        res.pop_back();
        chon(soTo + 1);
    }
    
public:
    void _process()
    {
        _init();
        chon(0);
        print();
    }
};

// Bai _ATM nhanh can
//---------------------------------------------------------------- 2

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    _ATM _main;
    _main._process();
}