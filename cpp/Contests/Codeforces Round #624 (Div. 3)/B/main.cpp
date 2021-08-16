#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

string solve() {
    ll n, m;
    cin >> n >> m;
    ll a[n], p[m];
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (ll i = 0; i < m; ++i) {
        cin >> p[i];
        --p[i];
    }
    sort(p, p + m);
    vector <pll> block;
    block.emplace_back(p[0], p[0] + 2);
    for (ll i = 1; i < m; ++i) {
        if (p[i] < block.back().second) {
            block.back().second++;
        } else {
            block.emplace_back(p[i], p[i] + 2);
        }
    }
    for (auto i : block) {
        sort(a + i.first, a + i.second);
    }
    for (ll i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) {
            return "NO";
        }
    }
    return "YES";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
    return 0;
}

/**
1
3 2
3 2 1
1 2

**/
