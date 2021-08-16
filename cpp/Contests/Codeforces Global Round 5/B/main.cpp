#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll n;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n;
    vector <ll> a (n), b (n), c (n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    for (ll i = 0; i < n; ++i) {
        cin >> b[i];
        --b[i];
    }
    vector <ll> k (n);
    for (ll i = 0; i < n; ++i)
        k[b[i]] = i;
    for (ll i = 0; i < n; ++i)
        c[i] = k[a[i]];
    ll ans = 0;
    ll mx = c[0];
    for (ll i = 1; i < n; ++i) {
        if (c[i] > mx)
            mx = c[i];
        else
            ++ans;
    }
    cout << ans;
    return 0;
}
