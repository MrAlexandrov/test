#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll n, m;
vector <ll> a;

ll ceil (ll a, ll b) {
    return a / b + (a % b != 0);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n >> m;
    a.resize(n);
    for (ll i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        a[i] = a[i] + (i - m >= 0 ? a[i - m] : 0);
        ans += a[i];
        cout << ans << ' ';
    }
    return 0;
}

/**


**/
