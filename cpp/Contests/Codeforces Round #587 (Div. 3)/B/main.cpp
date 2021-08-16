#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll n;
vector <pll> a;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        a.push_back ({x, i + 1});
    }
    sort (a.rbegin(), a.rend());
    ll ans = 0;
    for (ll i = 0; i < n; ++i)
        ans += a[i].first * i + 1;
    cout << ans << '\n';
    for (pll i : a)
        cout << i.second << ' ';
    return 0;
}
