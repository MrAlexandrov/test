#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void solve() {
    ll n;
    cin >> n;
    ll cnt = log2(n);
    vector <ll> ans(cnt + 1, 1);
    ll now = 1 + cnt;
    ll mn = 1;
    for (ll i = 1; i <= cnt; ++i) {
        ans[i] = mn;
        ll t = min(2 * ans[i - 1] - ans[i], (ll)((n - now) / (cnt - i + 1)));
        ans[i] += t;
        now += t * (cnt - i + 1);
        mn = ans[i];
    }
    cout << cnt << '\n';
    ll mx = 1;
    for (ll i = 1; i <= cnt; ++i) {
        cout << ans[i] - mx << ' ';
        mx = ans[i];
    }
    cout << '\n';
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
