#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll solve() {
    ll n, x;
    cin >> n >> x;
    vector <ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    ll sum = 0;
    ll cnt = 0;
    for (ll i = 0; i < n; ++i) {
        ++cnt;
        sum += a[i];
        if (sum >= x * cnt) {
            continue;
        } else {
            return cnt - 1;
        }
    }
    return n;
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
