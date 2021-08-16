#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll n;
    cin >> n;
    vector <ll> a(n);
    ll now = 0;
    pll r = {-1, -1};
    map <ll, ll> m;
    m[0] = r.first;
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        now += a[i];
        if (m.find(now) != m.end()) {
            r = (r.first < m[now] + 1 ? make_pair(m[now] + 1, i) : r);
        }
        m[now] = i;
        if (a[i] == 0) {
            r = {i, i};
        }
        ans += i - r.first;
    }
    cout << ans << '\n';
    return 0;
}

/**
5
3 -1 2 -1 4

**/
