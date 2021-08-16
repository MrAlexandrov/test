#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll M = (ll)998244353;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll n, k;
    cin >> n >> k;
    vector <ll> p(n), a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
        a[p[i]] = i;
    }
    reverse(a.begin(), a.end());
    vector <ll> b;
    ll sum = (n * (n + 1) - (n - k) * (n - k + 1)) / 2;
    for (ll i = 0; i < k; ++i) {
        b.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    ll ans = 1;
    for (ll i = 1; i < k; ++i) {
        ans = (ans * (b[i] - b[i - 1])) % M;
    }
    cout << sum << ' ' << ans << '\n';
    return 0;
}

/**


**/
