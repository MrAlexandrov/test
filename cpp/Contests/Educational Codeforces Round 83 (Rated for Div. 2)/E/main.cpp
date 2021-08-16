#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll n;
    cin >> n;
    vector <ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector <vector <ll>> dp(n, vector <ll>(n + 1, -1));
    for (ll i = 0; i < n; ++i) {
        dp[i][i + 1] = a[i];
    }
    for (ll len = 2; len <= n; ++len) {
        for (ll l = 0; l < n; ++l) {
            ll r = l + len;
            if (r > n) {
                break;
            }
            for (ll m = l + 1; m < r; ++m) {
                if (dp[l][m] != -1 && dp[l][m] == dp[m][r]) {
                    dp[l][r] = dp[l][m] + 1;
                    break;
                }
            }
        }
    }
    vector <ll> pref(n + 1, n + 8);
    pref[0] = 0;
    for (ll r = 1; r <= n; ++r) {
        for (ll l = 0; l < r; ++l) {
            if (dp[l][r] == -1) {
                continue;
            }
            pref[r] = min(pref[r], pref[l] + 1);
        }
    }
    cout << pref[n];
    return 0;
}

/**


**/
