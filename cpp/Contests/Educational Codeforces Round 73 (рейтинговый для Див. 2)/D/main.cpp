#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll INF = (1e18 + 1);

ll q;

ll min3 (ll a, ll b, ll c) {
    return min (a, min (b, c));
}

ll solve () {
    ll n;
    cin >> n;
    vector <pll> x (n + 1);
    for (ll i = 1; i <= n; ++i)
        cin >> x[i].first >> x[i].second;

    ll dp[n + 1][3] {};

    for (ll i = 0; i < n; ++i)
        for (ll j = 0; j < 3; ++j)
            dp[i][j] = INF;

    for (ll i = 0; i < 3; ++i) dp[1][i] = i * x[1].second;

    for (ll i = 2; i <= n; ++i)
        for (ll j = 0; j < 3; ++j)
            dp[i][j] = min3 ((x[i - 1].first + 0LL == x[i].first + j ? INF : dp[i - 1][0] + j * x[i].second),
                             (x[i - 1].first + 1LL == x[i].first + j ? INF : dp[i - 1][1] + j * x[i].second),
                             (x[i - 1].first + 2LL == x[i].first + j ? INF : dp[i - 1][2] + j * x[i].second));
    return min3 (dp[n][0], dp[n][1], dp[n][2]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> q;
    while (q--)
        cout << solve () << '\n';
    return 0;
}
