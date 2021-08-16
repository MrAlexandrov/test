#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = 2e4;

void solve() {
    ll x, y, z;
    cin >> x >> y >> z;
    ll ans = INT_MAX;
    ll aa = x, bb = y, cc = z;
    for (ll a = 1; a <= N; ++a) {
        for (ll b = a; b <= N; b += a) {
            for (ll c = b; c <= N; c += b) {
                ll cnt = abs(a - x) + abs(b - y) + abs(c - z);
                if (cnt < ans) {
                    ans = cnt;
                    aa = a, bb = b, cc = c;
                }
            }
        }
    }
    cout << ans << '\n';
    cout << aa << ' ' << bb << ' ' << cc << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/**


**/
