#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void solve() {
    string t;
    cin >> t;
    ll n = t.size();
    ll zero = 0, one = 0;
    for (char i : t) {
        zero += i == '0';
        one += i == '1';
    }
    if (zero == n || one == n) {
        return void(cout << t << '\n');
    }
    for (ll i = 0; i < n; ++i) {
        cout << "01";
    }
    cout << '\n';
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
