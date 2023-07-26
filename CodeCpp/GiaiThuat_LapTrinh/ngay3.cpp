#include <bits/stdc++.h>
using namespace std;

struct student
{
    string ho;
    string dem;
    string ten;
    float diem;
};

bool cmpa(student o1, student o2)
{
    return (o1.ten < o2.ten || (o1.ten == o2.ten && 
           (o1.ho < o2.ho || (o1.ho == o2.ho && 
           (o2.dem <= o2.dem)))));
}

bool cmpc(student o1, student o2)
{
    return (o1.diem >= o2.diem);
}

void print(student o1)
{
    if (o1.dem != "")
            cout << o1.ho << " " << o1.dem << " " << o1.ten << "\n";
        else
            cout << o1.ho << " " << o1.ten << "\n";
}
student arr[201];

void hocsinhngoan()
{
    int n; cin >> n;
    string tmp;
    vector<string> tens;
    for (int i = 0; i < n; i++)
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, tmp); 
        cin >> arr[i].diem;
        int space1 = tmp.find(" "), space2 = tmp.rfind(" ");
        arr[i].ho = tmp.substr(0, space1);
        if (space1 != space2) arr[i].dem = tmp.substr(space1 + 1, space2 - space1 - 1);
        arr[i].ten = tmp.substr(space2 + 1, tmp.length() - (space2 + 1));
    }

    sort(arr, arr + n, cmpa);
    for (int i = 0; i < n; i++)
    {
        print(arr[i]);
        if (find(tens.begin(), tens.end(), arr[i].ten) == tens.end()) tens.push_back(arr[i].ten);
    }

    cout << tens.size() << "\n";
    for (auto i : tens) cout << i << "\n";

    sort(arr, arr + n, cmpc);
    int cnt = 0, i = 0;
    while (cnt < 3 && i < n)
    {
        print(arr[i]);
        i++;
        while (arr[i].diem == arr[i - 1].diem && i < n)
        {
            print(arr[i]);
            i++;
        }
        cnt++;
    }
}

//---------------------------------------------------------------- 1

void soLuongSau()
{
    string s; cin >> s;
    vector<string> tokens;
    for (int len = 1; len <= s.length(); len++)
    {
        for (int i = 0; i < s.length(); i++)
        {
            string tmp = s.substr(i, len);
            if (find(tokens.begin(), tokens.end(), tmp) == tokens.end())
                tokens.push_back(tmp);
        }
    }
    cout << tokens.size() << "\n";
    for (auto i : tokens) cout << i << "\n";

}

//---------------------------------------------------------------- 2

string numToStr(int num)
{
    string s;
    if (num == 0) return "0";
    while (num > 0)
    {
        s.push_back(char(num % 10 + 48));
        num /= 10;
    }
    return s;
}

vector<string> maxString;

void maxXoaK()
{
    int n, k; 
    cin >> n >> k;
    string s;
    for (int i = 1; i <= n; i++) s = s + numToStr(i);
    for (int i = 0; i < s.length() - k; i++)
        maxString.push_back(s.substr(0, i) + s.substr(i + k, s.length() - (i + k + 1)));
    sort(maxString.begin(), maxString.end(), greater<string>());
    cout << maxString.front();
}

//---------------------------------------------------------------- 3

struct phanSo
{
    string chuoi;
    int so;
};

bool cmpps(phanSo ps1, phanSo ps2)
{
    return (ps1.so <= ps2.so);
}

vector<phanSo> ps;
vector<string> chuoi;
vector<int> so;

void maxPhanSo()
{
    int n , k;
    cin >> n >> k;
    for (int mau = 1; mau <= n; mau++)
        for (int tu = 0; tu <= mau; tu++)
        {
            if (find(so.begin(), so.end(), (tu * 1000 / mau * 1000)) == so.end())
            {   
                so.push_back(tu * 1000 / mau * 1000);
                chuoi.push_back(numToStr(tu) + '/' + numToStr(mau));
            }
        }
    
    for (int i = 0; i < so.size(); i++)
    {
        phanSo tmp;
        tmp.so = so[i];
        tmp.chuoi = chuoi[i];
        ps.push_back(tmp);
    }
    sort(ps.begin(), ps.end(), cmpps);
    cout << ps[k - 1].chuoi << "\t=\t" << ps[k - 1].so / 1e6;
}

//---------------------------------------------------------------- 4

int freq[27];
void higFreq()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
        freq[s[i] - 'a']++;
    int cnt = 0, maxCh = 0;
    char c;
    for (int i = 0; i <= 26; i++)
    {
        if (freq[i] > 0) cnt++;
        if (freq[i] > maxCh) 
        {
            maxCh = freq[i];
            c = char(i + 'a');
        }
    }
    cout << "Co " << cnt << " ki tu xuat hien trong chuoi\n";
    cout << "Ki tu " << c << " xuat hien " << maxCh << " lan";
}

//---------------------------------------------------------------- 5

void tronBanhTrang()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    vector<int> c(n + m);
    int cur1 = 0, cur2 = 0, cur3 = 0;
    while (cur1 < n && cur2 < m)
    {
        if (a[cur1] <= b[cur2])
        {
            c[cur3] = a[cur1];
            cur1++;
        } else
        {
            c[cur3] = b[cur2];
            cur2++;
        }
        cur3++;
    }
    while (cur1 < n) c[cur3++] = a[cur1++];
    while (cur2 < m) c[cur3++] = b[cur2++];
    for (int i = 0; i < c.size(); i++) cout << c[i] << "\t";

}

//---------------------------------------------------------------- 6


int main() 
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    tronBanhTrang();
    return 0;
}
