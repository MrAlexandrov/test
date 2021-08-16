#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll A = 26;

ll solve() {
    ll res = 0;
    ll n;
    cin >> n;
    vector <ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    vector <vector <ll>> pref(1, vector <ll>(A, 0));
    pref[0][a[0]]++;
    for (ll i = 1; i < n; ++i) {
        pref.push_back(pref[i - 1]);
        pref[i][a[i]]++;
    }
    res = *max_element(pref.back().begin(), pref.back().end());
    for (ll i = 0; i < n; ++i) {
        for (ll j = i; j < n; ++j) {
            ll mid = 0, lr = 0;
            for (ll k = 0; k < A; ++k) {
                mid = max(mid, pref[j][k] - (i - 1 < 0 ? 0 : pref[i - 1][k]));
                lr = max(lr, 2 * min((i - 1 < 0 ? 0 : pref[i - 1][k]), - pref[j][k] + pref[n - 1][k]));
            }
            res = max(res, mid + lr);
        }
    }
    return res;
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
