#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll n, m, d;
ll sum = 0;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n >> m >> d;
    vector <ll> c (m);
    for (ll i = 0; i < m; ++i) {
        cin >> c[i];
        sum += c[i];
    }
    sum = n - sum;
    if (sum > (d - 1) * (m + 1)) {
        cout << "NO\n";
        return 0;
    }
    else {
        cout << "YES\n";
    }
    vector <ll> ans (n, 0);
    ll ptr = 0;
    for (ll i = 0; i < m; ++i) {
        ll x = min (d - 1, sum);
        sum = max (0LL, sum - (d - 1));
        ptr += x;
        ll y = ptr;
        for (; ptr < y + c[i]; ++ptr)
            ans[ptr] = i + 1;
    }
    for (ll i : ans)
        cout << i << ' ';
    return 0;
}
