#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

int main ()
{
    cin >> n;
    vector <vector <ll>> a (60 + 8, vector <ll> {});
    vector <ll> b (n);
    for (ll i = 0; i < n; ++i)
        cin >> b[i];
    for (ll i = 0; i < n; ++i) {
        ll x = b[i];
        ll cnt = 0;
        while (x % 2 == 0)
            x >>= 1,
            ++cnt;
        a[cnt].push_back (b[i]);
    }/*
    for (ll i = 0; i < 60 + 8; ++i) {
        cout << i << "  ";
        for (ll j : a[i])
            cout << j << ' ';
        cout << '\n';
    }//*/
    ll mx = 0;
    for (ll i = 0; i < 60 + 8; ++i)
        if (a[mx].size() < a[i].size())
            mx = i;

    vector <ll> delite;
    for (ll i = 0; i < 60 + 8; ++i)
        if (i != mx)
            for (ll j : a[i])
                delite.push_back (j);

    cout << delite.size() << '\n';
    for (ll i : delite)
        cout << i << ' ';
    return 0;
}
