#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll INF = 1e18 + 8;

void max_self (ll &a, ll b) {
    a = max(a, b);
}

void min_self (ll &a, ll b) {
    a = min(a, b);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll n, m;
    cin >> n >> m;
    vector <ll> weight(n), value(n);
    for (ll i = 0; i < n; ++i)
        cin >> weight[i] >> value[i];
    ll sum_value = accumulate(value.begin(), value.end(), 0LL);
    vector <ll> dp(sum_value + 1, INF);                                 ///minimum weight to reach this value
    dp[0] = 0;
    for (ll i = 0; i < n; ++i)
        for (ll j = sum_value - value[i]; j >= 0; --j)
            min_self(dp[j + value[i]], dp[j] + weight[i]);
    ll ans = 0;
    for (ll i = 0; i <= sum_value; ++i)
        if (dp[i] <= m)
            max_self(ans, i);
    cout << ans;
    return 0;
}

/**


**/
