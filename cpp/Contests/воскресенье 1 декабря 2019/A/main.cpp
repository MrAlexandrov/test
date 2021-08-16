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
    vector <pll> a(n);
    for (ll i = 0; i < n; ++i)
        cin >> a[i].second >> a[i].first;
    sort(a.begin(), a.end());
    ll r = 0;
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        if (r < a[i].second) {
            r = a[i].first;
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}

/**


**/
