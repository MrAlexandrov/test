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
        --a[i];
    }
    vector <ll> tyt;
    vector <ll> ans(n, -1);
    for (ll i = 0; i < n; ++i) {
        if (ans[i] != -1) {
            continue;
        }
        ll now = i;
        tyt.push_back(i);
        now = a[now];
        while (now != i) {
            tyt.push_back(now);
            now = a[now];
        }
        ll cnt = 1;
        while (a[now] != i) {
            now = a[now];
            ++cnt;
        }
        for (ll j : tyt) {
            ans[j] = cnt;
        }
        tyt.clear();
    }
    for (ll i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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
