#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll q;

bool check (ll m, ll a, ll b, ll c) {
    ll a1 = a, b1 = b, c1 = c;
    if (a1 >= m && b1 >= m) {
        a1 -= m;
        b1 -= m;
        if (a1 + b1 + c1 >= m)
            return true;
        else
            return false;
    }
    else
        return false;
}

void solve () {
    ll a, b, c;
    cin >> a >> b >> c;
    ll l = 0, r = ((a + b + c) / 3) + 1;
    while (r - l > 1) {
        ll m = l + r >> 1;
        if (check (m, a, b, c))
            l = m;
        else
            r = m;
    }
    cout << l << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> q;
    while (q--)
        solve ();
    return 0;
}
