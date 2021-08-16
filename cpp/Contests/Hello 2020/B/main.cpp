#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll INF = INT_MAX;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    vector <bool> good(n, false);
    vector <ll> mn(n, INF), mx(n, -INF);
    for (ll i = 0; i < n; ++i) {
        ll m;
        cin >> m;
        for (ll j = 0; i < m; ++j) {
            ll x;
            cin >> x;
            mn[i] = min(mn[i], x);
            mx[i] = max(mx[i], x);
            if (mn[i] < mx[i]) {
                good[i] = true;
            }
        }
    }
    vector <pll> bad;
    for (ll i = 0; i < n; ++i) {
        if (!good[i]) {
            bad.emplace_back(mn[i], mx[i]);
        }
    }
    ll cnt_good = n - bad.size();
    ll ans = 2LL * cnt_good * n;
    sort(bad.begin(), bad.end());
    ///
    return 0;
}

/**


**/
