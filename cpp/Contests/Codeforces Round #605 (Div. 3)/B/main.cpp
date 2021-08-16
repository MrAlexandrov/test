#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void solve () {
    string s;
    cin >> s;
    map <char, ll> m;
    for (char i : s)
        ++m[i];
    ll x = min(m['L'], m['R']);
    ll y = min(m['U'], m['D']);
    if (x && y) {
        cout << 2 * (x + y) << endl;
        for (ll i = 0; i < x; ++i)
            cout << 'L';
        for (ll i = 0; i < y; ++i)
            cout << 'U';
        for (ll i = 0; i < x; ++i)
            cout << 'R';
        for (ll i = 0; i < y; ++i)
            cout << 'D';
    } else if (x == 0) {
        cout << min(2 * y, 2LL) << endl;
        for (ll i = 0; i < min(1LL, y); ++i)
            cout << 'U';
        for (ll i = 0; i < min(1LL, y); ++i)
            cout << 'D';
    } else if (y == 0) {
        cout << min(2 * x, 2LL) << endl;
        for (ll i = 0; i < min(1LL, x); ++i)
            cout << 'L';
        for (ll i = 0; i < min(1LL, x); ++i)
            cout << 'R';
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll q;
    cin >> q;
    while (q--)
        solve();
    return 0;
}

/**


**/
