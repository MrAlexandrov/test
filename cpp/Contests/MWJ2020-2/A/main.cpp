#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll a1 = a, b1 = b, c1 = c, d1 = d;
    ll t[3][3]{};

    t[0][0] = min(a, b);
    a -= t[0][0];
    b -= t[0][0];
    t[0][2] = min(a, c);
    a -= t[0][2];
    c -= t[0][2];
    t[2][2] = min(c, d);
    c -= t[2][2];
    d -= t[2][2];
    t[2][0] = min(b, d);
    b -= t[2][0];
    d -= t[2][0];

    t[0][1] = a;
    t[1][0] = b;
    t[1][2] = c;
    t[2][1] = d;

    ll sum = 0;
    for (ll i = 0; i < 3; ++i)
        for (ll j = 0; j < 3; ++j)
            sum += t[i][j];
    cout << sum << endl;
    for (ll i = 0; i < 3; ++i) {
        for (ll j = 0; j < 3; ++j)
            cout << t[i][j] << ' ';
        cout << endl;
    }   cout << endl;

    cout << a1 + b1 + c1 + d1 << endl;
    for (ll i = 0; i < 3; ++i)
        for (ll j = 0; j < 3; ++j)
            t[i][j] = 0;
    t[0][1] = a1;
    t[1][0] = b1;
    t[1][2] = c1;
    t[2][1] = d1;
    for (ll i = 0; i < 3; ++i) {
        for (ll j = 0; j < 3; ++j)
            cout << t[i][j] << ' ';
        cout << endl;
    }
    return 0;
}

/**


**/
