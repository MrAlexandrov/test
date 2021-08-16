#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = 4e5 + 8;

ll b[N]{};

ll solve() {
    ll res;
    ll n, k;
    cin >> n >> k;
    res = n;
    vector <ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (ll i = 0; i < n / 2; ++i) {
        ll l = a[i], r = a[n - i - 1];
        b[l + r]--;
        b[l + r + 1]++;
        b[min(l, r) + 1]--;
        b[max(l, r) + k + 1]++;
    }
    ll x = res;
    for (ll i = 0; i < 2 * k + 8; ++i) {
        x += b[i];
        b[i] = 0;
        res = min(res, x);
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
