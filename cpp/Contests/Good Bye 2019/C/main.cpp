#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void solve() {
    ll n;
    cin >> n;
    vector <ll> a(n);
    ll sum = 0;
    ll xr = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        xr ^= a[i];
    }
    vector <ll> ans;
    ans.push_back(xr);
    sum += xr;
    xr ^= xr;
    ans.push_back(sum);
    sum += sum;
    xr ^= sum;
    cout << ans.size() << endl;
    for (ll i : ans)
        cout << i << ' ';
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

/**


**/

