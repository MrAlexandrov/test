#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = 2 * 1e5 + 8;

ll n, k;
string s;

vector <ll> dp (N, 0LL);
vector <ll> r (N);

int main() {
    cin >> n >> k;
    cin >> s;
    r[n + 1] = 2 * n + k;

    for (ll i = n; i >= 1; --i)
        r[i] = (s[i - 1] == '1' ? i : r[i + 1]);

    for (ll i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1] + i;
        ll l = r[max (1LL, i - k)];
        if (l <= i + k)
            dp[i] = min (dp[i], dp[max (1LL, l - k) - 1] + l);
    }

    cout << dp[n] << '\n';
    return 0;
}
