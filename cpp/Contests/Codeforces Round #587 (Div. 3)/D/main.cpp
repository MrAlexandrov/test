#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll n;
vector <ll> a;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n;
    a.resize(n);
    for (ll i = 0; i < n; ++i)
        cin >> a[i];
    ll mx = *max_element (a.begin(), a.end());
    ll g = 0;
    for (ll i = 0; i < n; ++i)
        g = __gcd (g, mx - a[i]);
    ll cnt = 0;
    for (ll i = 0; i < n; ++i)
        cnt += (mx - a[i]) / g;
    cout << cnt << ' ' << g;
    return 0;
}
