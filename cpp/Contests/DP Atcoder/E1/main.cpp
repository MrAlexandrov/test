#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void max_self (ll &a, ll b) {
    a = max(a, b);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll n, m;
    cin >> n >> m;
    ll dp[m + 1]{};
    for (ll i = 0; i < n; ++i) {
        ll first, second;
        cin >> first >> second;
        for (ll j = m - first; j >= 0; --j)
            max_self(dp[j + first], dp[j] + second);
    }
    ll ans = 0;
    for (ll i : dp)
        max_self(ans, i);
    cout << ans;
    return 0;
}

/**


**/
