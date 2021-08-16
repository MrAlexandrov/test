#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

string solve() {
    ll n;
    cin >> n;
    vector <ll> a(n);
    set <ll> s;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] = ((a[i] % n) + n) % n;
        s.insert((i + a[i]) % n);
    }
    return (s.size() == n ? "YES" : "NO");
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
