#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = 1e5 + 8;

vector <ll> t1(N << 2, 0LL);
vector <ll> t2(N << 2, 0LL);

void upd1(ll v, ll tl, ll tr, ll pos, ll val) {
    if (tl == tr) {
        t1[v] = val;
        return;
    }
    ll tm = (tl + tr) >> 1;
    if (pos <= tm) {
        upd1(2 * v, tl, tm, pos, val);
    } else {
        upd1(2 * v + 1, tm + 1, tr, pos, val);
    }
    t1[v] = max(t1[2 * v], t1[2 * v + 1]);
}

void upd2(ll v, ll tl, ll tr, ll pos, ll val) {
    if (tl == tr) {
        t2[v] += val;
        return;
    }
    ll tm = (tl + tr) >> 1;
    if (pos <= tm) {
        upd2(2 * v, tl, tm, pos, val);
    } else {
        upd2(2 * v + 1, tm + 1, tr, pos, val);
    }
    t2[v] = max(t2[2 * v], t2[2 * v + 1]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll n, q;
    cin >> n >> q;
    bool a[2][N]{};
    for (ll i = 0; i < 2; ++i) {
        for (ll j = 0; j < n + 1; ++j) {
            a[i][j] = false;
        }
    }
    for (ll i = 0; i < q; ++i) {
        ll x, y;
        cin >> x >> y;
        ll k = 1;
        --x;
        if (a[x][y]) {
            k = -1;
        }
        a[x][y] = !a[x][y];
        if (x == 0) {
            upd1(1, 1, n, y, 100 * k);
            for (ll j = max(1LL, y - 1); j <= min(n, y + 1); ++j) {
                upd2(1, 1, n, j, 1 * k);
            }
        } else {
            upd2(1, 1, n, y, 100 * k);
            for (ll j = max(1LL, y - 1); j <= min(n, y + 1); ++j) {
                upd1(1, 1, n, j, 1 * k);
            }
        }
        cout << (t1[1] <= 100LL && t2[1] <= 100LL ? "Yes" : "No") << endl;
    }
    return 0;
}

/**


**/
