#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve() {
    ll n, g, b;
    cin >> n >> g >> b;
    ll half = (n + 1) / 2;
    ll l = 0, r = 1e18;
    while (r - l > 1) {
        ll m = (l + r) >> 1;
        ll full = m / (g + b);
        ll ost = m - full * (g + b);
        ll good = full * g + min(ost, g);
        ll bad = m - good;
        if (good >= half && n - good <= bad) {
            r = m;
        } else {
            l = m;
        }
    }
    return r;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}

/**


**/
