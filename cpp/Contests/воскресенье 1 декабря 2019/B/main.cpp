#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll n;
    cin >> n;
    vector <ll> a(n);
    vector <ll> cnt(1e6 + 8, 0);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    ll ans = 1;
    for (ll i = 0; i < a[i]; ++i) {
        ll now = 1;
        for (ll j = 2; j < ((1e6 + a[i] - 1) / a[i]); ++j)
            if (cnt[a[i] * j])
                ++now;
        ans = max(ans, now);
    }
    cout << ans << endl;
    return 0;
}

/**


**/
