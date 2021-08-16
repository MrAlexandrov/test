#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll solve() {
    ll n;
    cin >> n;
    map <ll, ll> a;
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        a[x]++;
    }
    ll mx = 0;
    for (auto i : a) {
        mx = max(mx, i.second);
    }
    return max(min((ll)a.size() - 1, mx), min((ll)a.size(), mx - 1));
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
