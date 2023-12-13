#include <bits/stdc++.h>
#define ll long long
using namespace std;
//--------------------------------------------------

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
ll Rand(ll l, ll r){
    if(l>r) swap(l,r);
    return abs(rd()*1LL*rd()%(r-l+1)+l);
}
//--------------------------------------------------
const string NAME = "BITMIN";
const int NTEST = 100;
void SINHTEST(ofstream &cout){
	ll n = abs(Rand(1, 1e5));
	ll q = abs(Rand(1, 1e5));
    cout << n << '\n';
	for (int i = 1; i <= n; i++) cout << (ll) Rand(1, 1e6) << ' '; cout << '\n';
	cout << q << '\n';
	for (int i = 1; i <= q; i++) {
	    ll p = Rand(0, 1);
	    if (p == 0) {
            ll x = abs(Rand(1, n)), v = abs(Rand(1, 1e6));
            cout << p << ' ' << 1ll*x << ' ' << 1ll*v << '\n';
	    }
	    else {
            ll l = abs(Rand(1, n)), r = abs(Rand(l, n));
            cout << p << ' ' << 1ll*l << ' ' << 1ll*r << '\n';
	    }
	}
}

const int N = 1e5+10;
int n, q, a[N];

struct SEQMENT {
    int st[N*4];

    void build(int i, int l, int r) {
        if (l == r) {
            st[i] = a[l];
            return;
        }
        int m = (l+r) >> 1;
        build(i*2, l, m);
        build(i*2+1, m+1, r);
        st[i] = min(st[i*2], st[i*2+1]);
    }

    void upd(int i, int l, int r, int u, int v) {
        if (u < l || r < u) return;
        if (l == r) {
            st[i] = v;
            return;
        }
        int m = (l+r) >> 1;

        upd(i*2, l, m, u, v);
        upd(i*2+1, m+1, r, u, v);
        st[i] = min(st[i*2], st[i*2+1]);
    }

    int get(int i, int l, int r, int u, int v) {
        if (r < u || v < l) return 1e9;
        if (u <= l && r <= v) return st[i];
        int m = (l+r) >>  1;

        return min(get(i*2, l, m, u, v), get(i*2+1, m+1, r, u, v));
    }
} myTree;

void solve(ifstream &cin, ofstream &cout) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    myTree.build(1, 1, n);
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int p, x, y; cin >> p >> x >> y;
        if (p == 0) myTree.upd(1, 1, n, x, y);
        else cout << myTree.get(1, 1, n, x, y) << '\n';
    }
}
//--------------------------------------------------

void execute(const string &command) {
    cerr << "Executing command [" + command +  "]... "<< endl;
    int err = system(command.c_str());
}
//--------------------------------------------------

int main(){
    srand(time(NULL));
    execute("md Test" + NAME);
    for (int iTest = 1; iTest <= NTEST; iTest++){
        ofstream inp((NAME + ".inp").c_str());
        SINHTEST(inp);
        inp.close();
        ifstream rinp((NAME + ".inp").c_str());
        ofstream rout((NAME + ".out").c_str());
        solve(rinp,rout);
        rinp.close();
        rout.close();
        execute("md Test" + to_string(iTest));
		execute("move " +NAME+ ".inp Test" + to_string(iTest));
		execute("move " +NAME+ ".out Test" + to_string(iTest));
		execute("move Test" + to_string(iTest) + " Test" + NAME);
    }
    return 0;
}

