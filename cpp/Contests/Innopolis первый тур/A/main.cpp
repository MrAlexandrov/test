#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll a, b, x, ans = 0;
    cin >> a >> b >> x;
    if (x == 0) {
        ans = 1000 / b;
        cout << ans * b;
        return 0;
    }
    if (x == 100) {
        ans = 1000 / a;
        cout << ans * a;
        return 0;
    }
    for (ll i = 0; i <= 1000; ++i) {
        for (ll j = 0; j <= 1000; ++j) {
            if ((100 * i * a) == x * (i * a + j * b) && i * a + j * b <= 1000) {
                ///cout << i << ' ' << j << '\n';
                ans = max(ans, i * a + j * b);
            }
        }
    }
    cout << ans;
    return 0;
}

/**


**/
