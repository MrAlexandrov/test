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
    ll n;
    cin >> n;
    while (n--) {
        ll c, sum;
        cin >> c >> sum;
        ll mn = sum / c;
        ll mx = sum % c;
        ll a = (c - mx) * mn * mn;
        ll b = mx * ceil(sum, c) * ceil(sum, c);
        cout << a + b << endl;
    }
    return 0;
}

/**


**/
