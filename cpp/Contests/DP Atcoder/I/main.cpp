#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cout.precision(20);
    ll n;
    cin >> n;
    vector <ld> p(n + 1);
    for (ll i = 1; i <= n; ++i)
        cin >> p[i];
    vector <vector <ld>> dp(2, vector <ld>(n + 1, 0));
    dp[0][0] = 1;
    for (ll i = 1; i <= n; ++i)
        for (ll j = 0; j <= i; ++j)
                dp[i & 1][j] = (j ? dp[(i - 1) & 1][j - 1] : 0) * p[i] + dp[(i - 1) & 1][j] * (1.0 - p[i]);
    ld ans = 0;
    for (ll j = n / 2 + 1; j <= n; ++j)
        ans += dp[n & 1][j];
    cout << ans << endl;
    return 0;
}

/**


**/
