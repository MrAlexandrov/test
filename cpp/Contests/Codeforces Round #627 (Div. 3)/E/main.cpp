#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll INF = INT_MAX;

ll n, h, l, r;
vector <ll> a;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n >> h >> l >> r;
    a.resize(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll dp[n + 1][h]{};
    for (ll i = 0; i <= n; ++i) {
        for (ll j = 0; j < h; ++j) {
            dp[i][j] = -INF;
        }
    }
    dp[0][0] = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < h; ++j) {
            if (dp[i][j] == -INF) {
                continue;
            }
            ll y = (j + a[i] - 1 + h) % h;
            dp[i + 1][y] = max(dp[i + 1][y], dp[i][j] + (l <= y && y <= r));
            y = (y + 1) % h;
            dp[i + 1][y] = max(dp[i + 1][y], dp[i][j] + (l <= y && y <= r));
        }
    }
    ll ans = 0;
    for (ll j = 0; j < h; ++j) {
        ans = max(ans, dp[n][j]);
    }
    cout << ans << '\n';
    return 0;
}

/**


**/
