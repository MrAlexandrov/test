#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void solve() {
    ll n, T, x, y;
    cin >> n >> T >> x >> y;
    vector <bool> b(n);
    vector <pll> a(n);
    for (ll i = 0; i < n; ++i) {
        ll t;
        cin >> t;
        if (t) b[i] = true;
        else b[i] = false;
    }
    for (ll i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = a[i].first + (b[i] ? y : x);
    }
    vector <ll> mx(n);
    mx[0] = a[i].second;
    for (ll i = 1; i < n; ++i)
        mx[i] = max(mx[i - 1], a[i].second);
    sort(a.begin(), a.end());
    ll l = 0, r = n + 1;
    while (r - l > 1) {
        ll m = l + r >> 1;
        ll t = upper_bound(a.begin(), a.end(), {mx[m - 1], 0LL}) - a.begin();
        if (t > m) {
            r = m;
            continue;
        }

    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll m;
    cin >> m;
    while (m--)
        solve(m);
    return 0;
}

/**


**/
