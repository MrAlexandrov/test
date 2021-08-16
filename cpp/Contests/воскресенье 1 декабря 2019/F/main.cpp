#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pll;

const ld EPS = 1e-9;
const ld INF = 1e12;
ll x, y;
ld ans = INF;

bool check (ll m) {
    ld res;

    if (m & 1) res = (ld)(x - y) / (m - 1);
    else res = (ld)(x + y) / m;

    if (res < y) res = INF;

    if (res < ans) {
        ans = res;
        return true;
    }
    else return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cout.precision(20);
    cin >> x >> y;
    if (y > x) {
        cout << -1 << endl;
        return 0;
    }
    if (x == y)
        ans = min(ans, (ld)x);
    ll l = 1, r = 1e9;
    while (r - l > 1) {
        ll m = l + r >> 1;
        if (check(m)) l = m;
        else r = m;
    }
    cout << fixed << ans << endl;
    return 0;
}

/**


**/
