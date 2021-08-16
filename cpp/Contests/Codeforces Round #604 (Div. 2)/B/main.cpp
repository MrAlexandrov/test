#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void solve () {
    ll n;
    cin >> n;
    vector <pll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i].first;
        --a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    ll mx = -1, mn = n + 1;
    for (ll i = 0; i < n; ++i) {
        ll t = a[i].second;
        mx = max(mx, t);
        mn = min(mn, t);
        if (mx - mn + 1 == i + 1) cout << 1;
        else cout << 0;
    }
    cout << endl;
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
