#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll INF = INT_MAX;

ll n, m;

ll solve(const vector <ll> &a) {
    ll res = n;
    vector <ll> cnt(n, 0LL);
    for (ll i = 0; i < n; ++i) {
        if (a[i] % m == 0 && a[i] <= n * m) {
            ++cnt[((i - (a[i] / m) + n) % n + n) % n];
        }
    }
    for (ll i = 0; i < n; ++i) {
        res = min(res, (n - cnt[i]) + i);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n >> m;
    vector <vector <ll>> a(m);
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            ll x;
            cin >> x;
            a[j].push_back(x - (j + 1));
        }
    }
    ll ans = 0;
    for (ll i = 0; i < m; ++i) {
        ans += solve(a[i]);
    }
    cout << ans << endl;
    return 0;
}

/**


**/
