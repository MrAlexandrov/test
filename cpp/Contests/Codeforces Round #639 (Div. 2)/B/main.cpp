#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    vector <ll> a = {2};
    ll x = 5;
    while (a.back() < (ll)1e9) {
        a.push_back(a.back() + x);
        x += 3;
    }
    ll T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        ll ans = 0;
        for (ll i = a.size() - 1; i >= 0 && n >= 2; --i) {
            ans += n / a[i];
            n %= a[i];
        }
        cout << ans << '\n';
    }
    return 0;
}

/**


**/
