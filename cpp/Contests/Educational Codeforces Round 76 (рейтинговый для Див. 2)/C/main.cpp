#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void solve () {
    ll n;
    cin >> n;
    vector <ll> b [n + 1];
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        b[x].push_back(i);
    }/*
    for (ll i = 1; i <= n; ++i) {
        cout << i << ": ";
        for (ll j : b[i])
            cout << j << ' ';
        cout << '\n';
    }   cout << endl;//*/
    ll ans = INT_MAX;
    for (ll i = 1; i <= n; ++i)
        if (b[i].size() >= 2)
            for (ll j = 0; j < b[i].size() - 1; ++j)
                ans = min (ans, 1 - b[i][j] + b[i][j + 1]);
    cout << (ans == INT_MAX ? -1 : ans) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll t;
    cin >> t;
    while (t--)
        solve ();
    return 0;
}

/**


**/
