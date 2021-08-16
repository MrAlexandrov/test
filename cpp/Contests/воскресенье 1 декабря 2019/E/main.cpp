#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll n, s;

ll cnt (ll x) {
    ll res = 0;
    while (x) {
        res += x / 10;
        x /= 10;
    }
    return res * 9;
}

bool check (ll m) {
    return (cnt(m) < s);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    cin >> n >> s;
    ll l = 9, r = (ll)1e18 + 1;
    while (r - l > 1) {
        ll m = l + r >> 1;
        if (check(m)) l = m;
        else r = m;
    }
    cout << max(0LL, n - l) << endl;
    return 0;
}

/**


**/
