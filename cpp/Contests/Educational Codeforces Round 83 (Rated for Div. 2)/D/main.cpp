#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = 2LL * (2e5 + 8);
const ll M = 998244353LL;

ll mul(ll a, ll b) {
    return (a * b) % M;
}

ll sum(ll a, ll b) {
    return (a + b) % M;
}

ll sub(ll a, ll b) {
    return (a - b + M) % M;
}

ll binpow(ll a, ll n) {
    if (n < 0) {
        return 0;
    }
    ll res = 1;
    while (n) {
        if (n & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}

ll rev(ll a) {
    return binpow(a, M - 2);
}

ll del(ll a, ll b) {
    return mul(a, rev(b));
}

vector <ll> fact = {1, 1};
ll n, m;

ll C(ll n, ll k) {
    if (k < 0 || n < 0 || n < k) {
        return 0;
    }
    ll res = 1LL;
    res = mul(res, fact[n]);
    ll znam = mul(rev(fact[k]), rev(fact[n - k]));
    return mul(res, znam);
}

ll a;

ll solve(ll x) {
    return mul(C(x - 1, n - 2), a);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (ll i = 2; i < N; ++i) {
        fact.push_back(mul(fact.back(), i));
    }
    cin >> n >> m;
    a = mul(n - 2, binpow(2, n - 3));
    ll ans = 0;
    for (ll i = 1; i <= m; ++i) {
        ans = sum(ans, solve(i));
    }
    cout << ans << endl;
    return 0;
}

/**


**/
