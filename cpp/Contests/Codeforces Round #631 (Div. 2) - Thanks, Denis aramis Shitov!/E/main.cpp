#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = (1LL << 20) + 8;

ll a[N];

void solve() {
    ll h, g;
    cin >> h >> g;
    ll sum = 0;
    for (ll i = 1; i < (1LL << h); ++i) {
        cin >> a[i];
        if ((1LL << (h - 1)) <= i) {
            sum += a[i];
        }
    }
    sum -= max(a[(1LL << h) - 2], a[(1LL << h) - 1]);

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

/**


**/
