#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll n;
vector <ll> a;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n;
    a.resize(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        a[i] -= x;
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        ll t = a.end() - upper_bound(a.begin(), a.end(), -a[i]);
        t -= (2 * a[i] > 0);
        ans += t;
    }
    cout << ans / 2 << endl;
    return 0;
}

/**


**/
