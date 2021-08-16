#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void solve() {
    ll n, p, k;
    cin >> n >> p >> k;
    vector <ll> a(n + 1);
    for (ll i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a.begin() + 1, a.end());

    ll ans = 0, sum = 0;
    for (ll i = 0; i < k; ++i) {
        sum += a[i];
        ll now = 0;
        if (sum <= p) now = i;
        ll cnt = sum, ptr = i;
        while (cnt <= p && ptr + k <= n) {
            ptr += k;
            cnt += a[ptr];
            if (cnt <= p) now = ptr;
        }
        ans = max(ans, now);
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

/**


**/
