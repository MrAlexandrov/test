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
        ll n;
        cin >> n;
        ll mn = INT_MAX, mx = INT_MIN;
        for (ll i = 0; i < n; ++i) {
            ll l, r;
            cin >> l >> r;
            mn = min(mn, r);
            mx = max(mx, l);
        }
        cout << max(mx - mn, 0LL) << '\n';
    }
    return 0;
}

/**


**/
