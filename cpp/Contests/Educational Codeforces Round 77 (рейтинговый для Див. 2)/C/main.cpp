#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll ceil (ll a, ll b) {
    return a / b + (a % b != 0);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll t;
    cin >> t;
    while (t--) {
        ll r, b, k;
        cin >> r >> b >> k;
        if (r > b) swap(r, b);
        if (__gcd(r, b) == 1 && ceil(b - 1, r) >= k) {
            cout << "REBEL" << endl;
            continue;
        }
        if (r * k < b) cout << "REBEL" << endl;
        else cout << "OBEY" << endl;
    }
    return 0;
}

/**
5
1 1 2
2 10 4
5 2 3
3 2 2
3 5 2

**/
