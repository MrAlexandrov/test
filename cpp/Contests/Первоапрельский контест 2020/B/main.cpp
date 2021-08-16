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
    for (ll i = 2; i < 1000; ++i) {
        while (n % i == 0) {
            cout << i;
            n /= i;
        }
    }
    return 0;
}

/**


**/
