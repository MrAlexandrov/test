#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll n;
    cin >> n;
    ll a = 1, b = n;
    for (ll i = 1; i <= n; ++i)
        if (n % i == 0)
            if (abs(i - (n / i)) < abs(a - b))
                a = i, b = n / i;
    if (a > b) swap(a, b);
    cout << a << ' ' << b;
    return 0;
}

/**


**/
