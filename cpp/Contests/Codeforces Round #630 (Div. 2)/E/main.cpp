#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

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
    ll res = 1;
    while (n) {
        if (n & 1) {
            res *= a;
            res %= M;
        }
        a *= a;
        a %= M;
        n >>= 1;
    }
    return res;
}

ll rev(ll a) {
    return binpow(a, M - 2);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll n, m, L, R;
    cin >> n >> m >> L >> R;
    bool x = (n & 1) && (m & 1);
    ll cnt = n * m;
    ll otr = R - L + 1;
    ll even = otr / 2, odd = otr / 2;
    if (otr & 1) {
        if (L & 1) {
            ++odd;
        } else {
            ++even;
        }
    }
    bool l = (cnt & 1) && (L & 1);
    bool r = (cnt & 1) && (R & 1);
    cout << odd << ' ' << even << endl;
    cout << otr << ' ' << cnt << endl;
    ll ans = binpow(otr, cnt);
    if (even == odd) {
        ans = mul(ans, rev(2));
    } else {
        ans = mul(sub(ans, 1), rev(2));
    }
    cout << ans << '\n';
    return 0;
}

/**


**/
