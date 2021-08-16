#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll m, n, k, t;
vector <ll> a;
vector <pair <ll, pll>> b;

bool check (ll x) {
    vector <ll> solve(2e5 + 8, 0);
    ll l = 0, r = k;
    while (r - l > 1) {
        ll mid = l + r >> 1;
        if (b[mid].first > x)
            r = mid;
        else
            l = mid;
    }
    for (ll i = r; i < k; ++i) {
        ++solve[b[i].second.first];
        --solve[b[i].second.second + 1];
    }
    ll now = 0, cnt = 0;
    for (ll i = 0; i < solve.size(); ++i) {
        now += solve[i];
        if (now > 0) ++cnt;
    }
    return (2 * cnt <= t);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> m >> n >> k >> t;
    t -= n + 1;
    a.resize(m);
    for (ll i = 0; i < m; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    b.resize(k);
    for (ll i = 0; i < k; ++i)
        cin >> b[i].second.first >> b[i].second.second >> b[i].first;
    sort(b.begin(), b.end());

    ll l = 0, r = a.back() + 1;
    while (r - l > 1) {
        ll mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    cout << a.size() - (lower_bound(a.begin(), a.end(), r) - a.begin());
    return 0;
}

/**


**/
