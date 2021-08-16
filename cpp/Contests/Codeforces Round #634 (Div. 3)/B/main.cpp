#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

string solve() {
    string res;
    ll n, a, b;
    cin >> n >> a >> b;
    for (ll i = 0; i < b; ++i) {
        res += (char)('a' + i);
    }
    while (res.size() < a) {
        res += res.back();
    }
    for (ll i = a; i < n; ++i) {
        res += res[i - a];
    }
    return res;
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
