#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void solve() {
    ll n;
    cin >> n;
    if (n % 4) {
        return void(cout << "NO\n");
    }
    cout << "YES\n";
    vector <ll> l = {1, 5}, r = {2, 4};
    n /= 2;
    while (l.size() < n) {
        l.push_back(l[l.size() - 2] + 6);
    }
    while (r.size() < n) {
        r.push_back(r[r.size() - 2] + 6);
    }
    for (ll i : r) {
        cout << i << ' ';
    }
    for (ll i : l) {
        cout << i << ' ';
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
