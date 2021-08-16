#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll INF = LLONG_MAX / 1e3;
ll n;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n;
    vector <pll> a (n + 1);
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort (a.begin(), a.end());

    vector <ll> dp (n + 1, INF);
    vector <ll> p (n + 1);
    dp[0] = 0;
    for (ll i = 0; i <= n; ++i) {
        for (ll j = 3; j <= 5; ++j) {
            if (i + j > n) break;
            ll cnt = a[i + j].first - a[i + 1].first;
            if (dp[i] + cnt < dp[i + j]) {
                dp[i + j] = dp[i] + cnt;
                p[i + j] = i;
            }
        }
    }
    cout << dp[n] << ' ';

    vector <ll> res (n + 1, 0);
    ll cnt = 1;
    ll ptr = n;
    ll before = 0;
    while (0 < ptr) {
        before = p[ptr];
        while (before < ptr)
            res[a[ptr--].second] = cnt;
        ++cnt;
    }
    cout << cnt - 1 << '\n';
    for (ll i = 1; i <= n; ++i)
        cout << res[i] << ' ';
    return 0;
}

/**


**/
