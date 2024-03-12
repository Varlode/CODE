///quan606303 : ttta ttta ttta ttta ttta ttta ttta ttta ttta
#include <bits/stdc++.h>
#define int long long
#define ll long long
#define INTMAX INT_MAX
#define INTMIN INT_MIN
#define LONGMAX LLONG_MAX
#define LONGMIN LLONG_MIN
#define fi first
#define se second
#define memfull(a,b) memset(a,b,sizeof(a));
#define endl '\n'
#define file(a) freopen(a".inp","r",stdin); freopen(a".out","w",stdout);
using namespace std;
const int MOD=1e9+7;
void solve()
{
    int cnt=0;
    int n,k;
    cin>>n>>k;
    int a[n+1];
    for (int i=1;i<=n;i++)
    {
     cin>>a[i];
    }
    for (int i=1;i<=n;i++)
    {
        if (a[i]==k)
        {
            cout<<"YES"<<endl;
            return ;
        }
        if (a[i]%k==0)cnt++;
        if (cnt>2)
        {
            cout<<"YES"<<endl;
            return ;
        }
    }
    cout<<"NO"<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //file("TEST");
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }

    return 0;
}
