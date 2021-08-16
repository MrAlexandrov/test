#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll k;
    cin >> k;
    while (k--) {
        ll n;
        cin >> n;
        vector <ll> a (n);
        for (ll i = 0; i < n; ++i)
            cin >> a[i];
        sort (a.begin(), a.end());
        for (ll i = 0; i < n; ++i)
        if (a[i] >= n - i) {
            cout << n - i << '\n';
            break;
        }
    }
    return 0;
}

/**


**/
