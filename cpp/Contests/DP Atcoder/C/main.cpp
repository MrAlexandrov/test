#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll n;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n;
    vector <vector <ll>> dp (n + 1);
    for (ll i = 1; i <= n; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        dp[i] = {a, b, c};
    }
    for (ll i = 2; i <= n; ++i)
        for (ll j = 0; j < 3; ++j)
            dp[i][j] = max ({(j == 0 ? 0LL : dp[i][j] + dp[i - 1][0]),
                             (j == 1 ? 0LL : dp[i][j] + dp[i - 1][1]),
                             (j == 2 ? 0LL : dp[i][j] + dp[i - 1][2])});

    cout << max ({dp[n][0], dp[n][1], dp[n][2]}) << '\n';
    return 0;
}
