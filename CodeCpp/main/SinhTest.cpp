#include <bits/stdc++.h>
using namespace std;
// Tên chương trình
const string NAME = "TASK";
// Số test kiểm tra
const int NTEST = 1000;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

// Viết lại hàm random để sử dụng cho thuận tiện. Hàm random này sinh ngẫu nhiên số trong phạm vi long long, số sinh ra >= l và <= h.
long long Rand(long long l, long long h) {
    assert(l <= h);
    return l + rd() % (h - l + 1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cerr.tie(0);
    srand(time(NULL));
    for (int iTest = 1; iTest <= NTEST; iTest++)
    {
        ofstream inp("TASK.inp");
        // Code phần sinh test ở đây
        int n = Rand(1, 30), m = Rand(3, 10);
        inp << n << ' ' << m << '\n';
        for (int i = 1; i <= n; i++) inp << Rand(0, 1);
        inp.close();
        /*
        system((NAME + "_trau.exe").c_str());
        system((NAME + ".exe").c_str());
        if (system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) == 0)
        {
            ofstream out((NAME + ".ans").c_str());
            out << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        ofstream out((NAME + ".ans").c_str());
        out << "Test " << iTest << ": CORRECT!\n";
        */
    }
    return 0;
}
