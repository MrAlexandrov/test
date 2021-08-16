#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void solve () {
    ll n;
    cin >> n;
    set <ll, greater <ll>> a;
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        if (x % 2 == 0)
            a.insert(x);
    }
    ll res = 0;
    while (!a.empty()) {
        ll t = *a.begin();
        a.erase(a.begin());
        t /= 2;
        ++res;
        if (t % 2 == 0)
            a.insert(t);
    }
    cout << res << endl;
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
