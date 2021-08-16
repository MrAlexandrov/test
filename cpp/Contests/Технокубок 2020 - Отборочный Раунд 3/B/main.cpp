#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void solve () {
    ll n;
    cin >> n;
    ll mx = 0;
    vector <ll> ans(n);
    set <ll> unused;
    for (ll i = 0; i < n; ++i)
        unused.insert(i + 1);
    vector <ll> a(n);
    for (ll i = 0; i < n; ++i)
        cin >> a[i];
    for (ll i = 0; i < n; ++i) {
        ll x = a[i];
        if (x > mx) {
            ans[i] = x;
            unused.erase(x);
            mx = x;
        }
        else {
            auto y = unused.lower_bound(0LL);
            if (y == unused.end()) {
                cout << "-1" << endl;
                return;
            }
            if (*y > mx) {
                cout << "-1" << endl;
                return;
            }
            ans[i] = *y;
            unused.erase(y);
        }
    }
    for (ll i : ans)
        cout << i << " ";
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

/**
4
5
1 3 4 5 5
4
1 1 3 4
2
2 2
1
1

1
2
2 2

**/
