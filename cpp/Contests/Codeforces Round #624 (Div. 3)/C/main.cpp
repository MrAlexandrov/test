#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void solve() {
    ll n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector <ll> p(m);
    for (ll i = 0; i < m; ++i) {
        cin >> p[i];
    }
    sort(p.begin(), p.end());
    p.push_back(n);
    vector <ll> ans(26, 0);
    vector <ll> now(26, 0);
    ll l = 0, r = 0;
    for (ll i = 0; i < p.size(); ++i) {
        r = p[i];
        for (ll j = l; j < r; ++j) {
            now[s[j] - 'a']++;
        }
        for (ll j = 0; j < 26; ++j) {
            ans[j] += now[j];
        }
        l = r;
    }
    for (ll i : ans) {
        cout << i << ' ';
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/**


**/
