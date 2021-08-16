#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void solve() {
    ll n;
    cin >> n;
    vector <ll> a(n);
    vector <ll> ans[2];
    for (ll i = 0; i < 2; ++i) {
        ans[i].resize(n);
    }
    bool ok = true;
    for (ll i = 0; i < n; ++i) {
        char s;
        cin >> s;
        a[i] = (s - '0');
        if (ok) {
            if (a[i] == 0 || a[i] == 2) {
                for (ll j = 0; j < 2; ++j) {
                    ans[j][i] = a[i] / 2;
                }
            } else {
                ans[1][i] = 1, ans[0][i] = 0;
                ok = false;
            }
        } else {
            ans[0][i] = a[i], ans[1][i] = 0;
        }
    }
    for (ll i = 0; i < 2; ++i) {
        for (ll j = 0; j < n; ++j) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
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
