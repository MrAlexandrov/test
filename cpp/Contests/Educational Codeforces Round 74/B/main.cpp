#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> q;
    while (q--) {
        ll n, R;
        cin >> n >> R;
        vector <ll> a (n);
        for (ll i = 0; i < n; ++i)
            cin >> a[i];
        sort (a.begin(), a.end());
        a.erase (unique (a.begin(), a.end()), a.end());
        n = a.size();/*
        for (ll i = 0; i < n; ++i)
            cout << a[i] << ' ';
        cout << '\n';*/
        ll cnt = 0;
        for (ll i = n - 1; i >= 0; --i) {
            if (cnt * R >= a[i])
                break;
            ++cnt;
        }
        cout << cnt << '\n';
    }
    return 0;
}
