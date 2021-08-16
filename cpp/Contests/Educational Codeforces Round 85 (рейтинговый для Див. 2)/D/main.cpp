#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void solve() {
    ll n, l, r;
    cin >> n >> l >> r;
    bool kek = false;
    if (r == n * (n - 1) + 1) {
        --r;
        kek = true;
    }
    for (ll i = 1; i < n && l <= r; ++i) {
        ll t = 2 * (n - i);
        if (l <= t) {
            t = min(t, r);
            if (l % 2 == 0) {
                cout << (l / 2) + i << ' ';
                ++l;
            }
            while (l <= t) {
                if (l <= t) {
                    cout << i << ' ';
                    ++l;
                }
                if (l <= t) {
                    cout << (l / 2) + i << ' ';
                    ++l;
                }
            }
        }
        l -= t;
        r -= t;
    }
    if (kek) {
        cout << 1;
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
