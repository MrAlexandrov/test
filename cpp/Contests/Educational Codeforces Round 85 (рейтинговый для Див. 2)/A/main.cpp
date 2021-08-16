#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

string solve() {
    ll n;
    cin >> n;
    ll p = 0, c = 0;
    bool ans = true;
    for (ll i = 0; i < n; ++i) {
        ll pi, ci;
        cin >> pi >> ci;
        ans &= pi >= p && ci >= c && pi - p >= ci - c;
        p = pi, c = ci;
    }
    return ans ? "YES" : "NO";
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
