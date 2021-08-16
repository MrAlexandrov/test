#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll INF = LLONG_MAX;

struct item {
    ll mn, ind;
    item (ll val, ll ptr) {
        mn = val; ind = ptr;
    }
    item () {
        mn = INF; ind = -1;
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
        res = (a.mn <= b.mn ? a : b);
        return res;
    }
    void build(ll v, ll tl, ll tr, const vector <ll> &a) {
        if (tr - tl == 1) {
            t[v] = item(a[tl], tl);
            return;
        }
        ll tm = (tl + tr) >> 1;
        build(2 * v + 1, tl, tm, a);
        build(2 * v + 2, tm, tr, a);
        t[v] = comb(t[2 * v + 1], t[2 * v + 2]);
    }
    item mn(ll v, ll tl, ll tr, ll l, ll r) {
        if (r <= tl || tr <= l) {
            return item();
        }
        if (l <= tl && tr <= r) {
            return t[v];
        }
        ll tm = (tl + tr) >> 1;
        return comb(mn(2 * v + 1, tl, tm, l, r), mn(2 * v + 2, tm, tr, l, r));
    }
};

vector <ll> ans;

ll solve(ll l, ll r, ST &T) {
    if (l >= r) {
        return 0;
    }
    item t = T.mn(0, 0, T.n, l, r);
    ll val = t.mn, m = t.ind;
    ll a = val * ((m + 1) - l) + solve(m + 1, r, T);
    ll b = val * (r - m) + solve(l, m, T);
    if (a > b) {
        for (ll i = l; i < m + 1; ++i) {
            ans[i] = val;
        }
    } else {
        for (ll i = m; i < r; ++i) {
            ans[i] = val;
        }
    }
    return max(a, b);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    ans.resize(n);
    vector <ll> m(n);
    for (ll i = 0; i < n; ++i) {
        cin >> m[i];
    }
    ST T(m);
    solve(0, T.n, T);
    for (ll i : ans) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}

/**


**/
