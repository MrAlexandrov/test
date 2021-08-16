#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pll;

string solve() {
    ll n, d;
    cin >> n >> d;
    if (d <= n) {
        return "YES";
    }
    ll t = INT_MAX;
    for (ll x = 0; x < n + 1; ++x) {
        ll t1 = x + ceil((ld)d / (x + 1));
        if (t1 <= n) {
            return "YES";
        }
        if (t < t1) {
            break;
        }
        t = t1;
    }
    return "NO";
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
