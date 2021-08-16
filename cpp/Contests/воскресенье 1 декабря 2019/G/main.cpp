#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll solve (ll n, ll x) {
    if (x == 2) {
        if (n & 1) return solve(n - 1, n - 1) + 1;
        else return (n / 2) + 1;
    }
    if (x & 1) return (x / 2) + 1;
    else {
        x >>= 1;
        return solve(n - (x - 1), 2) + (x - 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll n, q;
    cin >> n >> q;
    while (q--) {
        ll x;
        cin >> x;
        cout << solve(n, x) << endl;
    }
    return 0;
}

/**


**/
