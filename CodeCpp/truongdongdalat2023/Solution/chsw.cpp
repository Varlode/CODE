#include <bits/stdc++.h>
// define ctdl
#define ii pair<int,int>
#define fi first
#define se second
#define ll long long
// define files
#define TASKS "i."
#define fast ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
#define endl '\n'
#define all(x) x.begin(),x.end()

#define FORU(i,a,b) for(int i = a, _b = b; i <= _b ; i++)
#define FORD(i,a,b) for(int i = a, _b = b; i >= _b ; i--)


using namespace std;
const int maxn = 1000 ;
int n ;
int a[maxn+1] , b[maxn+1] ;
int f[10][10];

void enter()
{
    string s, t ; cin >> s >> t ;
    n = s.size() ;
    FORU(i,0,n-1)
    {
        a[i+1] = s[i] - '0' , b[i+1] = t[i] - '0' ;
        if(s[i] == '?') a[i+1] = 2 ;
    }
}
void solve()
{
    memset(f,0,sizeof(f)) ;
    FORU(i,1,n) f[a[i]][b[i]]++ ;
    if(f[0][1] + f[2][1] < f[1][0] )
    {
        cout << -1 ;
        return ;
    }
    int ans = 0 ;
    ans += f[2][1] + f[2][0] + max(f[1][0],f[0][1]) ;
    cout << ans ;
}


int main()
{
    fast ;
//    freopen(TASKS"INP","r",stdin) ;
//    freopen(TASKS"OUT","w",stdout) ;
    int t ; cin >> t ;
    while(t--)
    {
        enter() ;
        solve() ;
        cout << endl ;
    }
    return 0 ;
}
