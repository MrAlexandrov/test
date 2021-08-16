#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void solve() {
    ll n, d;
    cin >> n >> d;
    ll now = (n - 1) * n / 2;
    vector <ll> ans(n);
    ans[0] = 0;
    for (ll i = 1; i < n; ++i) {
        ans[i] = i - 1;
    }
    vector <ll> depth(n);
    depth[0] = 0;
    for (ll i = 1; i < n; ++i) {
        depth[i] = depth[ans[i]] + 1;
    }
    vector <ll> deg(n, 1);
    deg[n - 1] = 0;
    vector <set <ll>> free(14);
    for (ll i = 0; i < 14; ++i) {
        free[i].insert(i);
    }
    if (d > now) {
        cout << "NO" << '\n';
        return 0;
    }
    ll ptr = n - 1;
    while (now != d) {
        if (now > d) {
            ll ind = 0;
            for (ll i = 0; i < 14; ++i) {
                if (!free[i].empty()) {
                    ind = i;
                    break;
                }
            }
            if (depth[ptr] - ind <= now - d) {
                ans[ptr] -= ptr - (now - d);
                cout << "YES\n";
                for (ll i : ans) {
                    cout << i << ' ';
                }
                cout << '\n';
                return;
            }

        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/**


**/
