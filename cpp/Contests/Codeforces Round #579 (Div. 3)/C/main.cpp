#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll n;
    cin >> n;
    vector <ll> a(n);
    ll g = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        g = __gcd(g, a[i]);
    }
    ll ans = 0;
    for (ll i = 1; i <= sqrt(g); ++i) {
        if (g % i == 0) {
            ans += 2;
        }
    }
    if ((ll)sqrt(g) * (ll)sqrt(g) == g) --ans;
    cout << ans << endl;
    return 0;
}

/**


**/
