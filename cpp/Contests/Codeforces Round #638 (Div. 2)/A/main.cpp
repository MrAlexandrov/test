#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    vector <ll> two = {1LL};
    for (ll i = 0; i < 32; ++i) {
        two.push_back(two.back() << 1LL);
    }
    ll T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        ll a = two[n];
        for (ll i = 1; i < n / 2; ++i) {
            a += two[i];
        }
        ll b = 0;
        for (ll i = n / 2; i < n; ++i) {
            b += two[i];
        }
        cout << a - b << '\n';
    }
    return 0;
}

/**


**/
