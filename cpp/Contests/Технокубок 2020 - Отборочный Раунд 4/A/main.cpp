#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll cnt (ll x) {
    ll res = 0;
    while (x) {
        ++res;
        x /= 10;
    }
    return res;
}

void solve () {
    ll n;
    cin >> n;
    ll res = 0;
    ll sz = cnt(n);
    res = (sz - 1) * 9LL;
    ll ex = 0;
    for (ll i = 0; i < sz; ++i) {
        ex *= 10;
        ++ex;
    }
    ll k = ex;
    while (k <= n) {
        ++res;
        k += ex;
    }
    cout << res << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

/**


**/
