#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll n, k;

void solve() {
    cin >> n >> k;
    vector <ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector <bool> pick(n, false);
    for (ll i = 1; i < n - 1; ++i) {
        if (a[i - 1] < a[i] && a[i] > a[i + 1]) {
            pick[i] = true;
        }
    }
    ll ans = 0;
    ll x = 0, y = k - 1;

    ll cnt = 0;
    ll l = 0, r = k - 1;
    for (ll i = l + 1; i <= r - 1; ++i) {
        cnt += pick[i];
    }
    if (cnt > ans) {
        ans = cnt;
        x = l, y = r;
    }
    while (r < n) {
        cnt += pick[r];
        ++l, ++r;
        cnt -= pick[l];
        if (cnt > ans) {
            ans = cnt;
            x = l, y = r;
        }
    }
    cout << ans + 1 << ' ' << x + 1 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

/**


**/
