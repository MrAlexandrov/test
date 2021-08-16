#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        ll x = abs (a - b);
        ll ans = 0;
        ans += x / 5;
        x %= 5;
        if (x == 1 || x == 2) {
            ++ans;
        } else if (x == 3 || x == 4) {
            ans += 2;
        }
        cout << ans << '\n';
    }
    return 0;
}

/**


**/
