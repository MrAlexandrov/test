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
        ll n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        string a = s, b = t;
        sort (a.begin(), a.end());
        sort (b.begin(), b.end());
        if (a != b) {
            cout << "NO\n";
            continue;
        }
        bool ok = false;
        for (ll i = 0; i < n - 1; ++i)
            if (a[i] == a[i + 1])
                ok = true;
        if (ok) {
            cout << "YES\n";
            continue;
        }
        ll cnts = 0, cntt = 0;
        for (ll i = 0; i < n; ++i)
            for (ll j = i + 1; j < n; ++j) {
                cnts += (s[i] < s[j]);
                cntt += (t[i] < t[j]);
            }
        cout << (cnts % 2 == cntt % 2 ? "YES\n" : "NO\n");
    }
    return 0;
}
