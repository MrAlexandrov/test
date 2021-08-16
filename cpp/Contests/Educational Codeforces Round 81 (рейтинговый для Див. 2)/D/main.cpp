#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll Phi(ll n) {
    ll res = n;
    for (ll i = 2; i * i <= n; ++i) {
        ll cnt = 0;
        while (n % i == 0) {
            ++cnt;
            n /= i;
        }
        if (cnt) {
            res -= res / i;
        }
    }
    if (n > 1) {
        res -= res / n;
    }
    return res;
}

ll solve() {
    ll a, m;
    cin >> a >> m;
    return Phi(m / __gcd(a, m));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}

/**


**/
