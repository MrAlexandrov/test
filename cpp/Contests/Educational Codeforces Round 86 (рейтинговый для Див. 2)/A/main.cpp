#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll solve() {
    ll x, y;
    cin >> x >> y;
    ll a, b;
    cin >> a >> b;
    if (x + y == 0) {
        return 0LL;
    }
    ll ans = 0;
    ll d = min(x, y);
    ll mn = min(x, y), mx = max(x, y);
    ans += a * (mx - mn);
    ans += d * min(2 * a, b);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll T;
    cin >> T;
    while (T--) {
        cout << solve() << endl;
    }
    return 0;
}

/**


**/
