#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

string solve() {
    ll n;
    cin >> n;
    vector <ll> p(n);
    vector <ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
        a[p[i]] = i;
    }
    ll pos = 0;
    ll now = 0;
    ll r = n;
    while (r > 0) {
        for (ll i = a[now]; i < r - 1; ++i) {
            if (p[i] + 1 != p[i + 1]) {
                return "No";
            }
        }
        ll t = a[now];
        now = p[r - 1] + 1;
        r = t;
    }
    return "Yes";
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
