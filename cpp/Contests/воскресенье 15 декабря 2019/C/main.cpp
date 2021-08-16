#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll bin_pow (ll a, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1)
            res *= a;
        n >>= 1;
        a *= a;
    }
    return res;
}

ll n;
vector <ll> a(10, 0);
vector <bool> zero(10, true);

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        string s;
        cin >> s;
        zero[s[0] - 'a'] = false;
        reverse(s.begin(), s.end());
        for (ll j = 0; j < s.size(); ++j) {
            char x = s[j];
            a[x - 'a'] += bin_pow(10, j);
        }
    }
    ll mx = 0;
    bool was = false;
    for (ll i = 0; i < 10; ++i) {
        if (zero[i]) {
            if (was) {
                if (a[mx] < a[i])
                    mx = i;
            } else {
                mx = i;
                was = true;
            }
        }
    }
    if (was) a[mx] = 0;
    sort(a.rbegin(), a.rend());
    ll ans = 0;
    for (ll i = 0; i < 10; ++i)
        ans += a[i] * (i + 1);
    cout << ans << endl;
    return 0;
}

/**


**/
