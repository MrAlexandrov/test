#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll INF = INT_MAX;

void solve () {
    ll n;
    cin >> n;
    vector <ll> a(n);
    vector <ll> first(n, INF);
    vector <ll> last(n, -INF);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        first[a[i]] = min(first[a[i]], i);
        last[a[i]] = max(last[a[i]], i);
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    ll now = 0;
    ll mx = 0;
    ll ans = 0;
    n = a.size();
    for (ll i = 0; i < n; ++i) {
        if (i) {
            if (first[a[i]] > mx)
                ++now;
            else
                now = 1;
            mx = last[a[i]];
            ans = max(ans, now);
        }
        else {
            now = 1;
            mx = max(mx, last[a[i]]);
            ans = max(ans, now);
        }
    }
    cout << a.size() - ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll q;
    cin >> q;
    while (q--)
        solve();
    return 0;
}

/**


**/
