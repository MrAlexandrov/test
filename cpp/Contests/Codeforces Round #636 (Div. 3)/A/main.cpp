#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll solve() {
    ll n;
    cin >> n;
    ll two = 4;
    ll sum = 3;
    while (n % sum) {
        sum += two;
        two *= 2;
    }
    return (n / sum);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll T;
    cin >> T;
    while (T--) {
        cout << solve() << '\n';
    }
    return 0;
}

/**


**/
