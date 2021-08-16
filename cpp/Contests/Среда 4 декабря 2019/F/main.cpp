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
    ll cnt[4][2]{};
    for (ll i = 0; i < 4; ++i)
        for (ll j = 0; j < n; ++j)
            for (ll k = 0; k < n; ++k) {
                char x;
                cin >> x;
                cnt[i][(j + k) % 2] += (x == '1'),
                cnt[i][(j + k + 1) % 2] += (x == '0');
            }
    ll ans = INT_MAX;
    for (ll i = 0; i < (1 << 4); ++i) {
        if (__builtin_popcountll(i) == 2) {
            ll now = 0;
            for (ll j = 0; j < 4; ++j)
                now += cnt[j][(bool)(i & (1 << j))];
            ans = min(ans, now);
        }
    }
    cout << ans << endl;
    return 0;
}

/**


**/
