#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = 1e2 + 8;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector <ll> a(n), cnt(N, 0LL);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    vector <ll> ex;
    for (ll i = 0; i < N; ++i) {
        if (cnt[i]) {
            ex.push_back(i);
        }
    }
    if (ex.size() > k) {
        return void(cout << "-1\n");
    }
    for (ll i = 1; i <= n && ex.size() < k; ++i) {
        if (cnt[i] == 0) {
            ex.push_back(i);
        }
    }
    cout << n * ex.size() << '\n';
    for (ll i = 0; i < n; ++i) {
        for (ll j : ex) {
            cout << j << ' ';
        }
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
