#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll solve() {
    ll d, m;
    cin >> d >> m;
    ll lg = log2(d) + 1;
    vector <ll> cnt(lg + 1, 0);
    ll sum = 0;
    for (ll i = 1, t = 1; i <= lg; ++i, t = min(d, (t << 1) + 1LL)) {
        cnt[i] = t - sum;
        sum += cnt[i];
    }
    ll res = 1;
    for (ll i = 1; i <= lg; ++i) {
        res *= cnt[i] + 1;
        res %= m;
    }
    return (res - 1 + m) % m;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
    return 0;
}

/**


**/
