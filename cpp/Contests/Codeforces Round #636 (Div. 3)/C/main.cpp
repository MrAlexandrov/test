#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll solve() {
    ll n;
    cin >> n;
    vector <ll> a;
    ll x;
    cin >> x;
    a.push_back(x);
    for (ll i = 1; i < n; ++i) {
        cin >> x;
        if (a.back() * x > 0) {
            a.back() = max(a.back(), x);
        } else {
            a.push_back(x);
        }
    }
    ll ans = accumulate(a.begin(), a.end(), 0LL);
    return ans;
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
