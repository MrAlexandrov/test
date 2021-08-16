#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cout.precision(20);
    ll n;
    cin >> n;
    long double ans = 0;
    for (ll i = 0; i < n; ++i) {
        ans += (long double)1 / (i + 1);
    }
    cout << ans << endl;
    return 0;
}

/**


**/
