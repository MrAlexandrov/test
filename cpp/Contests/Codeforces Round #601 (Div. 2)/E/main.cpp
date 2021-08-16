#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll INF = 1e12 + 8;
ll n;
vector <ll> a;

ll check (ll x) {
    ll res = 0;
    for (ll i = 0; i < a.size(); i += x) {
        ll mid = a[(i + (i + x - 1)) / 2];
        for (ll j = i; j < i + x; ++j)
            res += abs(a[j] - mid);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        if (x)
            a.push_back(i);
    }
    ll sum = a.size();
    ll ans = INF;
    for (ll i = 2; i <= n; ++i)
        if (sum % i == 0)
            ans = min(ans, check(i));
    cout << (ans == INF ? -1 : ans) << endl;
    return 0;
}

/**


**/
