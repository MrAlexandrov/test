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
    vector <vector <ll>> a;
    ll x;
    cin >> x;
    a.push_back({x});
    for (ll i = 1; i < n; ++i) {
        cin >> x;
        if (x > a.back().back())
            a.back().push_back(x);
        else
            a.push_back({x});
    }
    ll m = a.size();
    ll ans = a[0].size();
    for (ll i = 0; i < m - 1; ++i) {
        ans = max(ans, (ll)a[i + 1].size());
        if (a[i].size() > 1) {
            if (a[i][a[i].size() - 2] < a[i + 1][0]) {
                ans = max(ans, (ll)a[i].size() - 1 + (ll)a[i + 1].size());
            }
        }
        if (a[i + 1].size() > 1) {
            if (a[i].back() < a[i + 1][1]) {
                ans = max(ans, (ll)a[i].size() + (ll)a[i + 1].size() - 1);
            }
        }
    }
    cout << ans << endl;
    return 0;
}

/**


**/
