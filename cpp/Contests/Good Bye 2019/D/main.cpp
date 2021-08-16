#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll n, k;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n >> k;
    vector <pll> a;
    for (ll i = 0; i < k + 1; ++i) {
        cout << "? ";
        for (ll j = 0; j < k + 1; ++j) {
            if (i != j) {
                cout << j + 1 << ' ';
            }
        }
        cout << endl;
        pll x;
        cin >> x.second >> x.first;
        a.push_back(x);
    }
    sort(a.rbegin(), a.rend());
    ll mx = a[0].first;
    ll ans = 0;
    for (ll i = 0; i < a.size(); ++i)
        ans += (a[i].first == mx);
    cout << "! " << ans << endl;
    return 0;
}

/**


**/
