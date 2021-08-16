#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll solve() {
    ll n;
    string s;
    cin >> s;
    n = s.size();
    ll mx = 0;
    ll now = 0;
    for (ll i = 0; i < n; ++i) {
        if (s[i] == 'L') {
            ++now;
            mx = max(mx, now);
        } else {
            now = 0;
        }
    }
    return mx + 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
    return 0;
}

/**


**/
