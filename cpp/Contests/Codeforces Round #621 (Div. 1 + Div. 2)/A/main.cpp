#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve() {
    ll n, d;
    cin >> n >> d;
    vector <ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll ans = a[0];
    for (ll i = 1; i < n; ++i) {
        if (a[i] * i <= d) {
            ans += a[i];
            d -= a[i] * i;
        } else {
            ans += d / i;
            break;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}

/**


**/
