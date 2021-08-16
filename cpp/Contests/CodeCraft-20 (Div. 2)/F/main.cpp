#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = 3e5 + 8;
const ll M = 1e9 + 7;

ll sum(ll a, ll b) {
    return (a + b) % M;
}

ll mul(ll a, ll b) {
    return (a * b) % M;
}

ll sub(ll a, ll b) {
    return (a - b + M) % M;
}

ll binpow(ll a, ll n) {
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

struct item {
    ll ans;
    ll l, r;
    ll cnt;
    item(ll val) {
        ans = 0,
        l = r = val;
        cnt = 1;
    }
    item() {
        ///
    }
};

struct ST {
    ll n;
    vector <item> T;
    ST(vector <ll> &a) {
        n = a.size();
        T.resize(n << 2);
        build(0, 0, n, a);
    }
    item comb(item a, item b) {
        item res;
        ///
    }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);

    return 0;
}

/**


**/
