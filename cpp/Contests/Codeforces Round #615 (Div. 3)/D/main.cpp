#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = 4e5 + 8;

pll t[N << 2]{};
ll q, x;

pll calc(pll a, pll b) {
    if (a.first == b.first) {
        return {a.first, min(a.second, b.second)};
    } else {
        return (a.first < b.first ? a : b);
    }
}

void build(ll v, ll tl, ll tr) {
    if (tl == tr) {
        t[v] = {0, tl};
        return;
    }
    ll tm = (tl + tr) >> 1;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    t[v] = calc(t[2 * v], t[2 * v + 1]);
}

void update(ll v, ll tl, ll tr, ll x) {
    if (tl == tr) {
        t[v].first++;
        t[v].second = tl;
        return;
    }
    ll tm = (tl + tr) >> 1;
    if (x <= tm) {
        update(2 * v, tl, tm, x);
    } else {
        update(2 * v + 1, tm + 1, tr, x);
    }
    t[v] = calc(t[2 * v], t[2 * v + 1]);
}

ll ans() {
    return t[1].first * x + t[1].second - 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> q >> x;
    build(1, 1, x);
    for (ll i = 0; i < q; ++i) {
        ll n;
        cin >> n;
        n %= x;
        update(1, 1, x, n + 1);
        cout << ans() << endl;
    }
    return 0;
}

/**


**/
