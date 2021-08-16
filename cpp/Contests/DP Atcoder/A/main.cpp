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
    vector <ll> a (n + 1);
    for (ll i = 1; i <= n; ++i)
        cin >> a[i];
    vector <ll> dp (n + 1);
    dp[1] = 0, dp[2] = abs (a[1] - a[2]);
    for (ll i = 3; i <= n; ++i)
        dp[i] = min (dp[i - 2] + abs (a[i - 2] - a[i]), dp[i - 1] + abs (a[i - 1] - a[i]));
    cout << dp[n] << '\n';
    return 0;
}
