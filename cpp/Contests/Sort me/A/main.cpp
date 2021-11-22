#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll n, ans = 0;
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        ll w, u;
        cin >> w >> u;
        ans += u;
    }
    cout << ans << endl;
    return 0;
}

/**


**/
