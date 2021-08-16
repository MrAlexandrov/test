#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = 2e5 + 8;
const ll M = 998244353;

ll binpow(ll a, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) {
            res *= a;
            res %= M;
        }
        a *= a;
        a %= M;
        n >>= 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll n;
    cin >> n;
    ll dp[N];
    dp[0] = 0;
    ll sum = 0;
    ll add = 0;
    for (ll i = 1; i <= n; ++i) {
        dp[i] = (i * binpow(10, i) - sum + M) % M;
        add += dp[i];
        add %= M;
        sum += add + dp[i];
        sum %= M;
    }
    for (ll i = n; i > 0; --i) {
        cout << dp[i] << ' ';
    }
    return 0;
}

/**


**/
