#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll INF = LLONG_MAX;

ll f(ll a, ll b, ll c) {
    return (a - b) * (a - b) + (b - c) * (b - c) + (c - a) * (c - a);
}

ll solve() {
    vector <vector <ll>> a(3);
    for (ll i = 0; i < 3; ++i) {
        ll x;
        cin >> x;
        a[i].resize(x);
    }
    for (ll i = 0; i < 3; ++i) {
        for (ll &j : a[i]) {
            cin >> j;
        }
        sort(a[i].begin(), a[i].end());
    }
    vector <ll> prem = {0, 1, 2};
    ll ans = INF;
    do {
        ll zero = prem[0], one = prem[1], two = prem[2];
        for (ll i = 0; i < a[zero].size(); ++i) {
            ll x = a[zero][i];
            auto l = upper_bound(a[one].begin(), a[one].end(), x);
            auto r = lower_bound(a[two].begin(), a[two].end(), x);
            if (l == a[one].begin() || r == a[two].end()) {
                continue;
            }
            --l;
            ans = min(ans, f(*l, x, *r));
        }
    }
    while (next_permutation(prem.begin(), prem.end()));
    return ans;
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
