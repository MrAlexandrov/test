#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = 2e2 + 8;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll n, m, k;
    cin >> n >> m >> k;
    for (ll i = 0; i < 2 * k; ++i) {
        ll x, y;
        cin >> x >> y;
    }
    string ans;
    for (ll i = 0; i < n - 1; ++i) {
        ans += 'U';
    }
    for (ll j = 0; j < m - 1; ++j) {
        ans += 'L';
    }
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m - 1; ++j) {
            ans += (i & 1 ? 'L' : 'R');
        }
        if (i != n - 1) {
            ans += 'D';
        }
    }
    cout << ans.size() << '\n';
    cout << ans << '\n';
    return 0;
}

/**


**/
