#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll INF = LLONG_MAX;

struct item {
    ll mn;
    bool isadd = false;
    ll add = 0;
    item() {
        mn = INF;
    }
    item(ll val) {
        mn = val;
    }
};

struct ST {
    ll n;
    vector <item> t;
    ST(vector <ll> &a) {
        n = a.size();
        t.resize(n << 2);
        build(0, 0, n, a);
    }
    item comb(item &a, item &b) {
        return (a.mn < b.mn ? a : b);
    }
    void build(ll v, ll tl, ll tr, vector <ll> &a) {
        if (tr - tl == 1) {
            t[v] = item(a[tl]);
            return;
        }
        ll tm = (tl + tr) / 2;
        build(2 * v + 1, tl, tm, a);
        build(2 * v + 2, tm, tr, a);
        t[v] = comb(t[2 * v + 1], t[2 * v + 2]);
    }
    void push(ll v, ll tl, ll tr) {
        if (t[v].isadd) {
            ll val = t[v].add;
            t[v].isadd = false;
            t[v].add = 0;

            t[v].mn += val;

            if (!(tr - tl == 1)) {
                t[2 * v + 1].isadd = t[2 * v + 2].isadd = true;
                t[2 * v + 1].add += val;
                t[2 * v + 2].add += val;
            }
        }
    }
    ll mn(ll v, ll tl, ll tr, ll l, ll r) {
        push(v, tl, tr);
        if (r <= tl || tr <= l) {
            return INF;
        }
        if (l <= tl && tr <= r) {
            return t[v].mn;
        }
        ll tm = (tl + tr) / 2;
        return min(mn(2 * v + 1, tl, tm, l, r), mn(2 * v + 2, tm, tr, l, r));
    }
    void add(ll v, ll tl, ll tr, ll l, ll r, ll val) {
        push(v, tl, tr);
        if (r <= tl || tr <= l) {
            return;
        }
        if (l <= tl && tr <= r) {
            t[v].isadd = true;
            t[v].add += val;
            push(v, tl, tr);
            return;
        }
        ll tm = (tl + tr) / 2;
        add(2 * v + 1, tl, tm, l, r, val);
        add(2 * v + 2, tm, tr, l, r, val);
        t[v] = comb(t[2 * v + 1], t[2 * v + 2]);
    }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll n;
    cin >> n;
    vector <ll> p(n);
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        --x;
        p[x] = i;
    }
    vector <ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector <ll> b(n);
    b[0] = a[0];
    for (ll i = 1; i < n; ++i) {
        b[i] = b[i - 1] + a[i];
    }
    ST T(b);
    ll l = 0, r = n;
    ll ans = T.mn(0, 0, n, l, r - 1);
    for (ll i = 0; i < n; ++i) {
        ll m = p[i];
        ll val = a[m];
        T.add(0, 0, n, l, m, val);
        T.add(0, 0, n, m, r, -val);
        ans = min(ans, T.mn(0, 0, n, l, r - 1));
    }
    cout << ans << endl;
    return 0;
}

/**


**/
