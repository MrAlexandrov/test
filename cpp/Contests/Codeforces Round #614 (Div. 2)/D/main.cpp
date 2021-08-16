#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll dist(pll a, pll b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll x0, y0, ax, ay, bx, by;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by;
    ll xs, ys, t;
    cin >> xs >> ys >> t;
    vector <pll> a = {{x0, y0}};
    while (a.back().first > 0 && a.back().second > 0) {
        a.emplace_back(a.back().first * ax + bx, a.back().second * ay + by);
    }
    a.pop_back();
    ll n = a.size();
    ll ans = 0;
    pll q = {xs, ys};
    for (ll i = 0; i < n; ++i) {
        for (ll j = i + 1; j < n; ++j) {
            ll now = 0;
            now += min(dist(q, a[i]), dist(q, a[j]));
            now += dist(a[i], a[j]);
            if (now <= t) {
                ans = max(ans, j - i + 1);
            }
        }
    }
    cout << ans << endl;
    return 0;
}

/**


**/
