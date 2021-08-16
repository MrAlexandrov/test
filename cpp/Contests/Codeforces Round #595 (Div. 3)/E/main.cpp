#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll INF = LLONG_MAX;

ll n, c;
vector <ll> a, b;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n >> c;
    a.resize(n), b.resize(n);
    for (ll i = 1; i < n; ++i) {
        cin >> a[i];
    }
    for (ll i = 1; i < n; ++i) {
        cin >> b[i];
    }
    vector <vector <ll>> dp(2, vector <ll>(n, INF));
    dp[0][0] = 0;
    dp[1][0] = c;
    for (ll i = 1; i < n; ++i) {
        dp[0][i] = min(dp[0][i - 1] + a[i], dp[1][i - 1] + a[i]);
        dp[1][i] = min(dp[0][i - 1] + c + b[i], dp[1][i - 1] + b[i]);
    }
    for (ll i = 0; i < n; ++i) {
        cout << min(dp[0][i], dp[1][i]) << ' ';
    }
    return 0;
}

/**


**/
