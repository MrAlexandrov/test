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
    for (auto &i : a) {
        cin >> i;
    }
    ll mx = a[0];
    for (ll i = 1; i < n; ++i) {
        a[i] = a[i] + mx;
        mx = max(mx, a[i]);
    }
    for (ll i : a) {
        cout << i << ' ';
    }
    return 0;
}

/**


**/
