#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll solve() {
    ll n, s, k;
    cin >> n >> s >> k;
    set <ll> m;
    for (ll i = 0; i < k; ++i) {
        ll x;
        cin >> x;
        m.insert(x);
    }
    ll ans = LLONG_MAX;
    for (ll i = s; i <= min(s + 1001, n); ++i) {
        if (m.find(i) == m.end()) {
            ans = min(ans, abs(s - i));
            break;
        }
    }
    for (ll i = s; i >= max(1LL, s - 1001); --i) {
        if (m.find(i) == m.end()) {
            ans = min(ans, abs(s - i));
            break;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}

/**


**/
