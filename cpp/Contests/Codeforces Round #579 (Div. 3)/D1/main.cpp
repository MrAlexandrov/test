#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

string s, t;

bool solve (string x) {
    ll n = x.size();
    ll ptr = 0;
    for (ll i = 0; i < n && ptr < t.size(); ++i)
        if (x[i] == t[ptr]) ++ptr;
    return (ptr == t.size());
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> s >> t;
    ll n = s.size();
    ll ans = 0;
    for (ll l = 1; l <= n; ++l)
        for (ll r = l; r <= n; ++r)
            if (solve(s.substr(0, l - 1) + s.substr(r, n)))
                ans = max(ans, r - l + 1);
    cout << ans << endl;
    return 0;
}

/**


**/
