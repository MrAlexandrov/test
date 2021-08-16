#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = 1e3 + 8;
ll n;
ll a[N][N]{};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n;
    for (ll i = 0; i < n; ++i)
        for (ll j = 0; j < n; ++j)
            cin >> a[i][j];
    ll a12 = a[0][1];
    ll a13 = a[0][2];
    ll a23 = a[1][2];
    ll x = sqrt (a12 * a13 / a23);
    cout << x << ' ';
    for (ll i = 1; i < n; ++i) {
        cout << a[0][i] / x << ' ';
    }
    return 0;
}

/**
3
0 8 14
8 0 28
14 28 0

3
0 8 16
8 0 32
16 32 0

**/
