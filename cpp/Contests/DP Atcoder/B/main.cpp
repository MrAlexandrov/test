#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll INF = INT_MAX;
ll n, k;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n >> k;
    vector <ll> a (n + 1);
    for (ll i = 1; i <= n; ++i)
        cin >> a[i];

    vector <ll> dp (n + 1, INF);

    dp[1] = 0;

    for (ll i = 1; i <= min (n, k); ++i)
        for (ll j = 1; j <= i; ++j)
            dp[i] = min (dp[i], dp[j] + abs (a[j] - a[i]));

    for (ll i = k + 1; i <= n; ++i)
        for (ll j = i - k; j <= i; ++j)
            dp[i] = min (dp[i], dp[j] + abs (a[j] - a[i]));

    cout << dp[n] << '\n';
    return 0;
}
