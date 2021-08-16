#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = 4e6 + 8;
ll n;
vector <pll> a;

ll t[N]{};

ll sum (ll v, ll tl, ll tr, ll l, ll r) {
    if (tl == l && tr == r)
        return t[v];
    ll tm = tl + tr >> 1;
    if (r <= tm)
        return sum(2 * v, tl, tm, l, r);
    if (tm < l)
        return sum(2 * v + 1, tm + 1, tr, l, r);
    return sum(2 * v, tl, tm, l, tm) + sum(2 * v + 1, tm + 1, tr, tm + 1, r);
}

void update (ll v, ll tl, ll tr, ll pos) {
    if (tl == tr) {
        t[v] = 1;
        return;
    }
    ll tm = tl + tr >> 1;
    if (pos <= tm)
        update(2 * v, tl, tm, pos);
    else
        update(2 * v + 1, tm + 1, tr, pos);
    t[v] = t[2 * v] + t[2 * v + 1];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n;
    a.resize(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        ll x = a[i].second + 1;
        ans += sum(1, 1, n, x, n);
        update(1, 1, n, x);
    }
    n %= 2;
    ans %= 2;
    cout << (n ^ ans ? "Um_nik" : "Petr") << endl;
    return 0;
}

/**


**/
