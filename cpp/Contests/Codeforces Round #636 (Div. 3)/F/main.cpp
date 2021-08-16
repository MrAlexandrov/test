#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = 2e2 + 8;

vector <ll> cnt(N, 0);

void solve() {
    ll n;
    cin >> n;
    vector <vector <ll>> a(n);
    for (ll i = 1; i < n; ++i) {
        ll x;
        cin >> x;
        a[i].resize(x);
        for (ll j = 0; j < x; ++j) {
            cin >> a[i][j];
            --a[i][j];
            cnt[a[i][j]]++;
        }
    }
    vector <bool> ok(n, true);
    vector <ll> ans(n);
    ll ptr = n - 1;
    ll now = 0;
    vector <ll> temp;
    while (ptr > 0) {
        if (temp.empty()) {
            for (ll i = 0; i < n; ++i) {
                if (cnt[i] == 1) {
                    now = i;
                    break;
                }
            }
        } else {
            for (ll i : temp) {
                if (cnt[i] == 1) {
                    now = i;
                    break;
                }
            }
        }
        ans[ptr--] = now;
        for (ll i = 1; i < n; ++i) {
            if (ok[i] && binary_search(a[i].begin(), a[i].end(), now)) {
                temp.clear();
                for (ll j : a[i]) {
                    if (j != now) {
                        temp.push_back(j);
                    }
                    cnt[j]--;
                }
                ok[i] = false;
                break;
            }
        }
    }
    set <ll> was;
    for (ll i = 0; i < n; ++i) {
        was.insert(i);
    }
    for (ll i = 1; i < n; ++i) {
        was.erase(ans[i]);
    }
    ans[0] = *was.begin();
    for (ll i = 0; i < n; ++i) {
        cout << ans[i] + 1 << ' ';
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll T;
    //cin >> T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}

/**
5
1 1
2 1 5
2 2 3
1 2

5
2 1 5
3 1 4 5
1 2
2 2 3

**/
