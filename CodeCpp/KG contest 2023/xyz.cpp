#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
const int N = 1e6;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f;

struct point {
    int x, y, z;
};

bool cmpy(const point a, const point b) {return a.y < b.y;}
bool cmpx(const point a, const point b) {return a.x < b.x;}

int n, ans = inf;
vector<point> p;

main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        point p0;
        cin >> p0.x >> p0.y >> p0.z;
        p.push_back(p0);
    }

    sort(p.begin(), p.end(), cmpx);

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {

            vector<point> p1;
            for (int k = 0; k < i; k++) p1.push_back(p[k]);
            for (int k = j + 1; k < n; k++) p1.push_back(p[k]);
            if (p1.size() < 2) continue;

            sort(p1.begin(), p1.end(), cmpy);
            
            int m = p1.size();
            vector<int> rmax(m+1, -inf), rmin(m+1, inf), lmax(m+1, -inf), lmin(m+1, inf);

            int maxz = -inf, minz = inf;

            lmax[0] = lmin[0] = p1[0].z;
            for (int ii = 1; ii < m; ii++) {
                lmax[ii] = lmin[ii] = p1[ii].z;
                lmax[ii] = max(lmax[ii], lmax[ii-1]);
                lmin[ii] = min(lmin[ii], lmin[ii-1]);
            }

            maxz = -inf; minz = inf;
            rmax[m-1] = rmin[m-1] = p1[m-1].z;
            for (int ii = m-2; ii >= 0; ii--) {
                rmax[ii] = rmin[ii] = p1[ii].z;
                rmax[ii] = max(rmax[ii], rmax[ii+1]);
                rmin[ii] = min(rmin[ii], lmin[ii+1]);
            }

            maxz = -inf; minz = inf;

            for (int ii = 0; ii < m; ii++) 
                for (int jj = ii; jj < m; jj++) {
                    if (m - (jj-ii+1) < 2) continue;
				    if (ii > 0) minz = min(minz, lmin[ii-1]), maxz = max(maxz, lmax[ii-1]);
				    if (jj < m-1) minz = min(minz, rmin[jj+1]), maxz = max(maxz, rmax[jj+1]);
                    ans = min(ans, p[j].x-p[i].x+p1[jj].y-p1[ii].y+maxz-minz);       
                }
        }
    }
    cout << ans;
}