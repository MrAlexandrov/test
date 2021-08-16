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
    if (a - b == 1 && c == 0 && d == 0) {
        cout << "YES" << endl;
        for (ll i = 0; i < b; ++i)
            cout << "0 1 ";
        cout << "0 ";
        return 0;
    }
    if (d - c == 1 && a == 0 && b == 0) {
        cout << "YES" << endl;
        for (ll i = 0; i < c; ++i)
            cout << "3 2 ";
        cout << "3 ";
        return 0;
    }
    if (a > b || c < d) {
        cout << "NO" << endl;
        return 0;
    }
    if (a == b && c == d) {
        cout << "YES" << endl;
        for (ll i = 0; i < a; ++i)
            cout << "0 1 ";
        for (ll i = 0; i < c; ++i)
            cout << "2 3 ";
        return 0;
    }
    if (a == b) {
        if (c - d == 1) {
            cout << "YES" << endl;
            for (ll i = 0; i < a; ++i)
                cout << "0 1 ";
            for (ll i = 0; i < d; ++i)
                cout << "2 3 ";
            cout << "2";
        }
        else cout << "NO" << endl;
        return 0;
    }
    if (c == d) {
        if (b - a == 1) {
            cout << "YES" << endl;
            for (ll i = 0; i < c; ++i)
                cout << "3 2 ";
            for (ll i = 0; i < a; ++i)
                cout << "1 0 ";
            cout << "1";
        }
        else cout << "NO" << endl;
        return 0;
    }
    if (abs((b - a) - (c - d)) <= 1) {
        cout << "YES" << endl;
        if (b - a == c - d) {
            for (ll i = 0; i < a; ++i)
                cout << "0 1 ";
            b -= a;
            for (ll i = 0; i < d; ++i)
                cout << "2 3 ";
            c -= d;
            for (ll i = 0; i < b; ++i)
                cout << "2 1 ";
            return 0;
        }
        if (b - a > c - d) {
            cout << "1 ";
            for (ll i = 0; i < a; ++i)
                cout << "0 1 ";
            b -= a + 1;
            for (ll i = 0; i < d; ++i)
                cout << "2 3 ";
            c -= d;
            for (ll i = 0; i < b; ++i)
                cout << "2 1 ";
            return 0;
        }
        if (c - d > b - a) {
            cout << "2 ";
            for (ll i = 0; i < d; ++i)
                cout << "3 2 ";
            c -= d + 1;
            for (ll i = 0; i < a; ++i)
                cout << "1 0 ";
            b -= a;
            for (ll i = 0; i < c; ++i)
                cout << "1 2 ";
            return 0;
        }
    }
    else cout << "NO" << endl;
    return 0;
}

/**
1 3 2 1

1 2 3 1

**/
