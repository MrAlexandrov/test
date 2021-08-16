#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void solve () {
    ll n, m;
    cin >> n >> m;
    vector <ll> a (n);
    for (ll i = 0; i < n; ++i)
        cin >> a[i];
    ll res = 0;
    vector <pll> ans;
    for (ll i = 0; i < n; ++i) {
        res += a[i] + a[(i + 1) % n];
        ans.push_back({i, (i + 1) % n});
    }
    if (n == 2 || ans.size() > m) {
        cout << "-1\n";
        return;
    }
    ll mn1 = 0, mn2 = 1;
    if (a[mn1] > a[mn2])
        swap (mn1, mn2);
    for (ll i = 2; i < n; ++i)
        if (a[i] <= a[mn2])
            if (a[mn1] > a[mn2])
                swap (mn1, mn2);
    ll delta = m - ans.size();
    for (ll i = 0; i < delta; ++i) {
        res += a[mn1] + a[mn2];
        ans.push_back({mn1, mn2});
    }
    cout << res << '\n';
    for (auto i : ans)
        cout << i.first + 1 << ' ' << i.second + 1 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll t;
    cin >> t;
    while (t--)
        solve ();
    return 0;
}

/**


**/
