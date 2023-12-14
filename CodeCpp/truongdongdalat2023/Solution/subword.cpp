#include<bits/stdc++.h>
using namespace std;

#define y1 as214
#define ii pair < int , int >
#define iii pair < int , ii >
#define iv pair < ii , ii >

#define fi first
#define se second
#define fr front()
#define pb push_back


#define FOR(i , x , n) for(ll i = x ; i <= n ; ++i)
#define REP(i , n) for(ll i = 0 ; i < n ; ++i)
#define FORD(i , x , n) for(ll i = x ; i >= n ; --i)

#define ll long long
#define oo INT_MAX
#define eps 1e-8
#define div divv
#define pow poww

string s , t;
deque < char > dq;

void toi_gian(string &s)
{
    while(true)
    {
        if(s.size() <= 1)
            break;
        bool check = false;
        for(int i = 0 ; i < s.size() ; i++)
        {
            if((s[i] == 'a' && s[i + 1] == 'A') ||
               (s[i] == 'A' && s[i + 1] == 'a') ||
               (s[i] == 'b' && s[i + 1] == 'B') ||
               (s[i] == 'B' && s[i + 1] == 'b'))
            {
                check = true;
                s.erase(s.begin() + i + 1);
                s.erase(s.begin() + i);
                break;
            }
        }
        if(!check)
            break;
    }
}

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s , t;
    cin >> s >> t;
    REP(s , t.size())
        dq.push_back(t[s]);
    toi_gian(s);
    toi_gian(t);
    ///cout << s << " " << t << endl;

    int start1 = -1 , end1 = -1 , start2 = -1 , end2 = -1 , len = 0;
    REP(i , t.size())
    {
        REP(j , s.size())
        {
            int dem = 0;
            FOR(k , 0 , 2000)
            {
                if(i + k >= t.size() || j + k >= s.size())
                    break;
                if(t[i + k] == s[j + k])
                    dem++;
                else
                    break;
            }
            if(len < dem)
            {
                len = dem;
                start1 = i;
                end1 = i + len - 1;
                start2 = j;
                end2 = j + len - 1;
            }
        }

    }
    //cout << len << " " << start2 << " "<< end2 << endl;
    FOR(j , 0 , start1 - 1)
    {
        if(t[j] == 'a')
            dq.push_front('A');
        else if(t[j] == 'A')
            dq.push_front('a');
        else if(t[j] == 'b')
            dq.push_front('B');
        else
            dq.push_front('b');
    }
    int sz = t.size();
    FORD(j , sz - 1 , end1 + 1)
    {
        if(t[j] == 'a')
            dq.push_back('A');
        else if(t[j] == 'A')
            dq.push_back('a');
        else if(t[j] == 'b')
            dq.push_back('B');
        else
            dq.push_back('b');
    }
    sz = s.size();
    FORD(j , start2 - 1 , 0)
    {
        //cout << j << " " << t[j] << endl;
        dq.push_front(s[j]);
    }
    FOR(j , end2 + 1 , sz - 1)
        dq.push_back(s[j]);
    REP(s , dq.size())
        cout << dq[s];
}
// aAaBababbA
// aAaBabaAbA
