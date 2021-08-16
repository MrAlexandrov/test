#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void solve() {
    ll n;
    cin >> n;
    vector <ll> three;
    while (n) {
        three.push_back(n % 3);
        n /= 3;
    }
    three.push_back(0);
    ll ptr = -1;
    for (ll i = three.size() - 1; i >= 0; --i) {
        ll j = i;
        while (three[j] == 2) {
            three[j + 1]++;
            ++j;
            ptr = j;
            i = -1;
        }
    }
    if (ptr != -1) {
        for (ll i = 0; i < ptr; ++i) {
            three[i] = 0;
        }
    }
    ll ans = 0;
    ll now = 1;
    for (ll i = 0; i < three.size(); ++i, now *= 3) {
        ans += now * three[i];
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/**


**/
