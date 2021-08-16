#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void solve() {
    ll n;
    cin >> n;
    vector <ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector <bool> pref(n, false);
    set <ll, greater <ll>> b;
    for (ll i = 0; i < n; ++i) {
        if (b.find(a[i]) != b.end()) {
            break;
        }
        b.insert(a[i]);
        if (b.size() == *b.begin()) {
            pref[i] = true;
        }
    }
    b.clear();
    vector <pll> ans;
    for (ll i = n - 1; i > 0; --i) {
        if (b.find(a[i]) != b.end()) {
            break;
        }
        b.insert(a[i]);
        if (b.size() == *b.begin()) {
            if (pref[i - 1]) {
                ans.emplace_back(i, n - i);
            }
        }
    }
    cout << ans.size() << '\n';
    for (auto i : ans) {
        cout << i.first << ' ' << i.second << '\n';
    }
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
