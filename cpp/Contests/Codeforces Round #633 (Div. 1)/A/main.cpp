#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = 1e5 + 8;
const ll INF = INT_MAX;

ll cnt(ll x) {
    ll res = 0;
    while (x) {
        ++res;
        x >>= 1;
    }
    return res;
}

struct item {
    ll mx, ind;
    item(ll val, ll x) {
        mx = val;
        ind = x;
    }
    item() {
        mx = -INF;
        ind = 0;
    }
};

struct ST {
    ll n;
    vector <item> t;
    ST (vector <ll> &a) {
        n = a.size();
        t.resize(n << 2);
        build(0, 0, n, a);
    }
    item comb(const item &a, const item &b) {
        item res;
        if (a.mx == b.mx) {
            res.ind = a.ind;
        } else {
            res.ind = (a.mx > b.mx ? a.ind : b.ind);
        }
        res.mx = max(a.mx, b.mx);
        return res;
    }
    void build(ll v, ll tl, ll tr, const vector <ll> &a) {
        if (tr - tl == 1) {
            if (tl < n) {
                t[v] = item(a[tl], tl);
            }
            return;
        }
        ll tm = (tl + tr) >> 1;
        build(2 * v + 1, tl, tm, a);
        build(2 * v + 2, tm, tr, a);
        t[v] = comb(t[2 * v + 1], t[2 * v + 2]);
    }
    item mx(ll v, ll tl, ll tr, ll l, ll r) {
        if (r <= tl || tr <= l) {
            return item();
        }
        if (l <= tl && tr <= r) {
            return t[v];
        }
        ll tm = (tl + tr) >> 1;
        return comb(mx(2 * v + 1, tl, tm, l, r), mx(2 * v + 2, tm, tr, l, r));
    }
};

ll solve() {
    ll res = 0;
    ll n;
    cin >> n;
    vector <ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ST T(a);
    ll r = n;
    while (r > 0) {
        item t = T.mx(0, 0, n, 0, r);
        ll mx = t.mx, ind = t.ind;
        ll rasn = 0;
        for (ll i = t.ind; i < r; ++i) {
            rasn = max(rasn, mx - a[i]);
        }
        res = max(res, cnt(rasn));
        r = ind;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll T;
    cin >> T;
    while (T--) {
        cout << solve() << '\n';
    }
    return 0;
}

/**


**/
