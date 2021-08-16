#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll r, c;
    cin >> r >> c;
    if (r == 1 && c == 1) {
        cout << 0 << endl;
        return 0;
    }
    vector <ll> a(r);
    vector <ll> b(c);
    if (r < c) {
        iota(a.begin(), a.end(), 1);
        iota(b.begin(), b.end(), r + 1);
    } else {
        iota(b.begin(), b.end(), 1);
        iota(a.begin(), a.end(), c + 1);
    }
    for (ll i = 0; i < r; ++i) {
        for (ll j = 0; j < c; ++j) {
            ll x = a[i], y = b[j];
            ll g = __gcd(x, y);
            cout << x * y / g << ' ';
        }
        cout << endl;
    }
    return 0;
}

/**


**/
