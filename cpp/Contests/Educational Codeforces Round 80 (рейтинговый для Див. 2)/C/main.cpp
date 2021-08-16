#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll M = 1e9 + 7;

ll n, m;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    m <<= 1;
    ll dp[m + 1][n]{};
    dp[0][0] = 1;
    for (ll i = 1; i <= m; ++i) {
        for (ll j = 0; j < n; ++j) {
            for (ll k = 0; k <= j; ++k) {
                dp[i][j] += dp[i - 1][k];
                dp[i][j] %= M;
            }
        }
    }
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        ans += dp[m][i];
        ans %= M;
    }
    cout << ans << endl;
    return 0;
}

/**


**/
