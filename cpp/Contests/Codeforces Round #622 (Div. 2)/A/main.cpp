#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll ans = 0;
    if (a) {
        --a;
        ++ans;
    }
    if (b) {
        --b;
        ++ans;
    }
    if (c) {
        --c;
        ++ans;
    }
    vector <vector <ll>> x = {
        {a, b, c}, {a, c, b}, {b, a, c}, {b, c, a}, {c, a, b}, {c, b, a}
    };
    sort(x.begin(), x.end());
    vector <ll> cnt(6, 0);
    for (ll i = 0; i < 6; ++i) {
        if (x[i][0] && x[i][1]) {
            --x[i][0], --x[i][1];
            ++cnt[i];
        }
        if (x[i][0] && x[i][2]) {
            --x[i][0], --x[i][2];
            ++cnt[i];
        }
        if (x[i][1] && x[i][2]) {
            --x[i][1], --x[i][2];
            ++cnt[i];
        }
        if (x[i][0] && x[i][1] && x[i][2]) {
            ++cnt[i];
        }
    }
    return ans + *max_element(cnt.begin(), cnt.end());
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


**/
