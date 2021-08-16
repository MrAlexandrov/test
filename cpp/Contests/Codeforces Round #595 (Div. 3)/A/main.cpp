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
        vector <ll> a(n);
        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        bool one = true;
        for (ll i = 0; i < n - 1; ++i) {
            if (a[i] + 1 == a[i + 1]) {
                one = false;
            }
        }
        cout << (one ? 1 : 2) << '\n';
    }
    return 0;
}

/**


**/
