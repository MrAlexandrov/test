#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll n, mx = 0;
vector <string> a;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n;
    a.resize(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        mx = max(mx, (ll)a[i].size());
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    for (ll i = 0; i < mx; ++i) {
        ll mn = INT_MAX;
        for (ll j = 0; j < 26; ++j) {
            ll lit = 0;
            for (ll k = 0; k < n; ++k)
                if (a[k].size() >= i + 1 && a[k][i] != char('a' + j))
                    ++lit;
            mn = min(mn, lit);
        }
        ans += mn;
    }
    cout << ans;
    return 0;
}

/**


**/
