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
    ll m = n / 2;
    vector <ll> a(m);
    for (ll i = 0; i < m; ++i) {
        cin >> a[i];
        --a[i];
    }
    sort(a.begin(), a.end());
    ll ans1 = 0, ans2 = 0;
    for (ll i = 0; i < m; ++i)
        ans1 += abs(a[i] - 2 * i);
    for (ll i = 0; i < m; ++i)
        ans2 += abs(a[i] - (2 * i + 1));
    cout << min(ans1, ans2) << endl;
    return 0;
}

/**


**/
