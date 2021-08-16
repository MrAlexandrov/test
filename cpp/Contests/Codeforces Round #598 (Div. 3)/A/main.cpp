#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll q;
    cin >> q;
    while (q--) {
        ll a, b, n, s;
        cin >> a >> b >> n >> s;
        ll k = s / n;
        s -= min (k, a) * n;
        if (s == 0 || s <= b)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
