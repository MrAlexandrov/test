#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector <bool> ans(n, false);
    for (ll i = 2; i < n + 8; ++i) {
        ll t = i * (i - 1) / 2;
        if (t >= k) {
            ans[i - 1] = true;
            ans[i - (t - k) - 2] = true;
            break;
        }
    }
    reverse(ans.begin(), ans.end());
    for (ll i = 0; i < n; ++i) {
        cout << char('a' + ans[i]);
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/**


**/
