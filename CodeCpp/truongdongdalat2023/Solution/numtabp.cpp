#include <bits/stdc++.h>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma GCC target("popcnt")

#define mp make_pair
#define F first
#define S second
#define All(v) (v).begin(),(v).end()
#define reset(x) memset((x),0,sizeof((x)))
#define pb push_back
#define endl '\n'
#define sz(x) int((x).size())

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;
typedef vector < int > vi;
//typedef __int128_t t128;
typedef tuple < int, int, int > tiii;

const bool hnnef = 0;
const int maxn = 102;
const int MOD = 1000000007;
const int base = 31;
const double eps = 1e-7;
const double oo = 2e23 + 7;
const long long inf = 1LL * MOD * MOD;

template <typename T1, typename T2> bool minimize(T1 &a, T2 b)
{
    if(a > b)
    {
        a = b;
        return true;
    }
    return false;
}

template <typename T1, typename T2> bool maximize(T1 &a, T2 b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

struct State {
    int t, x, y;
};

vector<int> Ba[maxn], Bb[maxn];
int idCompa[maxn], idCompb[maxn], numCompA, numCompB;
int a[maxn][maxn], b[maxn][maxn], idr[maxn], idc[maxn], posr[maxn], posc[maxn];
int anRow[maxn][2], anCol[maxn][2], bnRow[maxn][2], bnCol[maxn][2], gridSize;

void solve()
{
    cin >> gridSize;
    for (int i = 1; i <= gridSize; ++i) {
        for (int j = 1; j <= gridSize; ++j) {
            cin >> a[i][j];
            if(a[i][j]) {
                anRow[i][(anRow[i][0] > 0)] = j;
                anCol[j][(anCol[j][0] > 0)] = i;
            }
        }
    }

    for (int i = 1; i <= gridSize; ++i) {
        for (int j = 1; j <= gridSize; ++j) {
            cin >> b[i][j];
            if(b[i][j]) {
                bnRow[i][(bnRow[i][0] > 0)] = j;
                bnCol[j][(bnCol[j][0] > 0)] = i;
            }
        }
    }

    vector<pii> szA, szB;
    for (int i = 1; i <= gridSize; ++i) {
        for (int j = 1; j <= gridSize; ++j) {
            cin >> a[i][j];
            if(a[i][j] && !idCompa[i]) {
                ++numCompA;
                int tmpi(i);
                do {
                    Ba[numCompA].push_back(i);
                    idCompa[i] = numCompA;
                    j = anRow[i][0] ^ anRow[i][1] ^ j;
                    i = anCol[j][0] ^ anCol[j][1] ^ i;
                } while(i != tmpi);
                szA.push_back({sz(Ba[numCompA]), i});
            }
        }
    }

    for (int i = 1; i <= gridSize; ++i) {
        for (int j = 1; j <= gridSize; ++j) {
            cin >> b[i][j];
            if(b[i][j] && !idCompb[i]) {
                ++numCompB;
                int tmpi(i);
                do {
                    Bb[numCompB].push_back(i);
                    idCompb[i] = numCompB;
                    j = bnRow[i][0] ^ bnRow[i][1] ^ j;
                    i = bnCol[j][0] ^ bnCol[j][1] ^ i;
                } while(i != tmpi);
                szB.push_back({sz(Bb[numCompB]), i});
            }
        }
    }

    sort(szA.begin(), szA.end());
    sort(szB.begin(), szB.end());

    bool check = (sz(szA) == sz(szB));
    for (int it = min(sz(szA), sz(szB)) - 1; it >= 0; --it) {
        if(szA[it].F != szB[it].F) {
            check = 0;
            break;
        }
    }

    if(!check) {
        cout << "-1\n";
        return;
    }

    for (int i = 1; i <= gridSize; ++i)
        idr[i] = idc[i] = posr[i] = posc[i] = i;

    vector<State> ans;
    for (int it = 0; it < sz(szB); ++it) {
        int i(szB[it].S), ia(szA[it].S), jb(-1);
        for (int j = 1; j <= gridSize; ++j) {
            if(b[i][j]) {
                jb = j;
                break;
            }
        }

        if(idr[ia] != i) {
            ans.push_back({1, idr[ia], i});
            int tmp(idr[ia]);
            swap(idr[ia], idr[posr[i]]);
            swap(posr[tmp], posr[i]);
        }

        int t = (a[posr[i]][anRow[posr[i]][1]] == b[i][jb]);
        int ja(anRow[posr[i]][t]);
        if(idc[ja] != jb) {
            ans.push_back({2, idc[ja], jb});
            int tmp(idc[ja]);
            swap(idc[ja], idc[posc[jb]]);
            swap(posc[tmp], posc[jb]);
        }

        int cntn(0), szComp(szB[it].F);
        while(++cntn <= szComp) {
            int ja(posc[jb]);
            ja = anRow[posr[i]][0] ^ anRow[posr[i]][1] ^ ja;
            jb = bnRow[i][0] ^ bnRow[i][1] ^ jb;
            if(idc[ja] != jb) {
                ans.push_back({2, idc[ja], jb});
                int tmp(idc[ja]);
                swap(idc[ja], idc[posc[jb]]);
                swap(posc[tmp], posc[jb]);
            }

            int nai = anCol[posc[jb]][0] ^ anCol[posc[jb]][1] ^ posr[i], nbi = bnCol[jb][0] ^ bnCol[jb][1] ^ i;
            if(idr[nai] != nbi) {
                ans.push_back({1, idr[nai], nbi});
                int tmp(idr[nai]);
                swap(idr[nai], idr[posr[nbi]]);
                swap(posr[tmp], posr[nbi]);
            }

            i = nbi;
        }
    }

    cout << sz(ans) << '\n';
    for (int it = 0; it < sz(ans); ++it)
        cout << ans[it].t << ' ' << ans[it].x << ' ' << ans[it].y << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    #define Task "numtabp"
    if(fopen(Task".INP", "r"))
    {
        freopen(Task".INP", "r", stdin);
        freopen(Task".OUT", "w", stdout);
    }

    int tc = 1;
    if(hnnef)cin >> tc;
    while(tc--)
        solve();

    cerr << "\n" << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms";
    return 0;
}
