#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

string solve() {
    ll n, k;
    cin >> n >> k;
    vector <ll> a(n);
    ll sum = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    ll cnt = 0;
    for (ll i : a) {
        if (i) {
            ++cnt;
        }
    }
    while (cnt) {
        ll now = 0;
        for (ll i = 0; i < n; ++i) {
            if (a[i] % k == 0) {
                continue;
            } else if (a[i] % k == 1) {
                ++now;
                --a[i];
                cnt -= (a[i] == 0);
            } else {
                return "NO";
            }
        }
        if (now > 1) {
            return "NO";
        }
        for (ll i = 0; i < n; ++i) {
            a[i] /= k;
        }
    }
    return "YES";
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
