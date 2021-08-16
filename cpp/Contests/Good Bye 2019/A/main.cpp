#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void solve() {
    ll n, k1, k2;
    cin >> n >> k1 >> k2;
    ll mx1 = 0, mx2 = 0;
    for (ll i = 0; i < k1; ++i) {
        ll x;
        cin >> x;
        mx1 = max(mx1, x);
    }
    for (ll i = 0; i < k2; ++i) {
        ll x;
        cin >> x;
        mx2 = max(mx2, x);
    }
    cout << (mx1 > mx2 ? "YES" : "NO") << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

/**


**/
