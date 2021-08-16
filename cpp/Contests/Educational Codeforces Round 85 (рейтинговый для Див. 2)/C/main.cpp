#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll INF = (ll)2e12;

ll solve() {
    ll n;
    cin >> n;
    vector <ll> a(n), b(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    ll ans = 0, mn = INF;
    for (ll i = 0; i < n; ++i) {
        ll l = i - 1;
        if (l < 0) {
            l += n;
        }
        if (b[l] < a[i]) {
            ans += a[i] - b[l];
            a[i] = b[l];
        }
        mn = min(mn, a[i]);
    }
    return ans + mn;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll T;
    cin >> T;
    while (T--) {
        cout << solve() << '\n';
    }
    return 0;
}

/**


**/
