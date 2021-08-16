#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll ceil (ll x, ll y) {
    return x / y + (x % y != 0);
}

vector <char> ex;

void solve () {
    ll n, m, k;
    cin >> n >> m >> k;
    ll cnt = 0;
    vector <vector <char>> a (n, vector <char> (m));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            char x;
            cin >> x;
            a[i][j] = x;
            if (x == 'R')
                ++cnt;
        }
    }
    ll more = cnt % k;
    ll less = k - more;
    ll cntmore = ceil (cnt, k);
    ll cntless = (cnt - more * cntmore) / less;
    ll ptr = 0;
    ll now = (more ? cntmore : cntless);
    ///cout << more << ' ' << less << ' ' << cntmore << ' ' << cntless << '\n';
    for (ll i = 0; i < n * m; ++i) {
        ll x = i / m;
        ll y = (x % 2 == 0 ? i % m : m - (i % m) - 1);
        ///cout << x << ' ' << y << endl;
        if (a[x][y] == 'R') {
            a[x][y] = ex[ptr];
            --now;
            if (now == 0) {
                if (more)
                    --more;
                else
                    --less;
                if (more)
                    now = cntmore;
                else
                    now = cntless;
                if (more || less)
                    ++ptr;
            }
        }
        else {
            a[x][y] = ex[ptr];
        }
    }
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j)
            cout << a[i][j];
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    for (ll i = 0; i < 26; ++i)
        ex.push_back(char('a' + i)),
        ex.push_back(char('A' + i));
    for (ll i = 0; i < 10; ++i)
        ex.push_back(char('0' + i));
    ll t;
    cin >> t;
    while (t--)
        solve ();
    return 0;
}

/**
1
5 5 4
RRR..
R.R..
RRR..
R..R.
R...R

1
2 31 62
RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR
RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR


**/
