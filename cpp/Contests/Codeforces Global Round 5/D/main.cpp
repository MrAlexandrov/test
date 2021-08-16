#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = 1e5 + 8;
ll n;
vector <ll> a;
vector <ll> dp;
bitset <N> is_end;

ll ceil (ll a, ll b) {
    return a / b + (a % b != 0);
}

ll cnt (ll pos) {
    ll x, mx;
    x = mx = a[pos];
    for (ll i = pos; i < pos + 2 * n + 1; ++i) {
        if (i == pos + 2 * n)
            return -1;
        ll now = a[i % n];
        if (mx < now)
            mx = now;
        if (ceil (mx, 2) > now)
            return i - pos;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n;
    a.resize (n);
    dp.resize (n);

    for (ll i = 0; i < n; ++i)
        cin >> a[i];

    dp[0] = cnt (0);

    for (ll i = 1; i < n; ++i) {
        ll now = a[i];

        if (a[i - 1] <= now)
            dp[i] = dp[i - 1] - 1;
        else
            dp[i] = cnt (i);
    }
    for (ll i : dp)
        cout << (i < 0 ? -1 : i) << ' ';
    return 0;
}
