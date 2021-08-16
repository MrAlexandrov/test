#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll n;
vector <vector <ll>> a;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        ll x, h;
        cin >> x >> h;
        a.push_back({x, h, i});
    }
    sort(a.begin(), a.end());
    vector <ll> dp(n, 1);
    vector <ll> mx(n, 1);
    for (ll i = n - 1; i >= 0; --i) {
        ll t = a[i][0] + a[i][1] - 1;
        ll l = 0, r = n;
        while (r - l > 1) {
            ll m = l + r >> 1;
            if (a[m][0] <= t) {
                l = m;
            } else {
                r = m;
            }
        }
        dp[a[i][2]] = l - i + 1;
        if (dp[a[i][2]] >= 2)
            dp[a[i][2]] = max(dp[a[i][2]], mx[a[l][2]] + );
        if (dp[a[i][2]] >= 2)
            mx[a[i][2]] = (i == n - 1 ? 1LL : max(dp[a[i][2]], mx[a[i + 1][2]] + 1));
    }
    for (ll i : mx)
        cout << i << ' ';
    cout << endl;
    for (ll i : dp)
        cout << i << ' ';
    return 0;
}

/**
4
1 2
2 2
3 1
4 1

**/
