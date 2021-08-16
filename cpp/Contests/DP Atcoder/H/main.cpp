#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll M = 1e9 + 7;

ll sum (ll a, ll b) {
    return (a + b) % M;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll n, m;
    cin >> n >> m;
    char a[n][m];
    for (ll i = 0; i < n; ++i)
        for (ll j = 0; j < m; ++j)
            cin >> a[i][j];
    ll dp[n][m];
    dp[0][0] = 1;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            if (i || j) {
                if (a[i][j] == '.')
                    dp[i][j] = sum((i - 1 >= 0 ? dp[i - 1][j] : 0), (j - 1 >= 0 ? dp[i][j - 1] : 0));
                else
                    dp[i][j] = 0;
            }
        }
    }
    cout << dp[n - 1][m - 1];
    return 0;
}

/**


**/
