#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll bin_pow (ll a, ll n, ll m) {
    ll res = 1;
    while (n) {
        if (n & 1) {
            res *= a;
            res %= m;
        }
        n >>= 1;
        a *= a;
        a %= m;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll n, m;
    cin >> n >> m;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    ll ans = 0;
    vector <ll> a(n);
    iota(a.begin(), a.end(), 1LL);
    do {
        for (ll i = 0; i < n; ++i) {
            for (ll j = i; j < n; ++j) {
                ll mn = 100, mx = -100;
                for (ll k = i; k <= j; ++k) {
                    mn = min(mn, a[k]);
                    mx = max(mx, a[k]);
                }
                ans += (mx - mn == j - i);
            }
        }
    }
    while (next_permutation(a.begin(), a.end()));
    cout << ans << endl;
    ll f = 1;
    for (ll i = 1; i <= n; ++i)
        f *= i;
    cout << f * n * (n + 1) / 2 << endl;
    return 0;
}

/**


**/
