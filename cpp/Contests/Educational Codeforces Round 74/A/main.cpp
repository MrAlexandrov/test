#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void ans (bool x) {
    cout << (x ? "YES\n" : "NO\n");
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll t;
    cin >> t;
    while (t--) {
        ll x, y;
        cin >> x >> y;
        if (x - y < 2)
            ans (0);
        else
            ans (1);
    }
    return 0;
}
