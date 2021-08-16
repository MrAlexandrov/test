#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        set <ll> a;
        for (ll i = 0; i < n; ++i) {
            ll x;
            cin >> x;
            a.insert(x);
        }
        cout << a.size() << '\n';
    }
    return 0;
}

/**


**/
