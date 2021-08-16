#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = 2e5 + 8;
const ll M = 998244353LL;

vector <ll> f = {1LL};

ll mul(ll a, ll b) {
    return (a * b) % M;
}

ll sum(ll a, ll b) {
    return (a + b) % M;
}

ll binpow(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
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

ll C(ll n, ll k) {
    return mul(f[n], rev(mul(f[k], f[n - k])));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    for (ll i = 1; i < N; ++i) {
        f.push_back((f.back() * i) % M);
    }
    ll n, k;
    cin >> n >> k;
    if (k > n - 1) {
        return 0;
    }
    ll ans = 1LL;
    ll a = mul(C(n, n - k), C(n, n - k));
    cout << a << endl;
    ll b = binpow(n - k, k);
    ans = mul(a, b);
    ans = mul(ans, rev(binpow(k + 1, n - k - 1)));
    ans = mul(ans, 2);
    cout << ans << endl;
    return 0;
}

/**


**/
