#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void solve() {
    ll n;
    cin >> n;
    vector <bool> used(n, false);
    ll alone = -1;
    for (ll i = 0; i < n; ++i) {
        ll m, x;
        cin >> m;
        bool was = false;
        for (ll j = 0; j < m; ++j) {
            cin >> x;
            --x;
            if (was) {
                continue;
            }
            if (!used[x]) {
                used[x] = true;
                was = true;
            }
        }
        if (!was) {
            alone = i;
        }
    }
    if (alone == -1) {
        cout << "OPTIMAL\n";
    } else {
        cout << "IMPROVE\n";
        for (ll i = 0; i < n; ++i) {
            if (!used[i]) {
                cout << alone + 1 << ' ' << i + 1 << '\n';
                return;
            }
        }
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
