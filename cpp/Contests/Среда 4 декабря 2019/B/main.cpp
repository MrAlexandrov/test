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
    set <ll> was;
    deque <ll> ans;
    vector <ll> a(n);
    for (ll i = 0; i < n; ++i)
        cin >> a[i];
    reverse(a.begin(), a.end());
    for (ll i = 0; i < n; ++i) {
        if (was.find(a[i]) == was.end()) {
            was.insert(a[i]);
            ans.push_front(a[i]);
        }
    }
    cout << ans.size() << endl;
    for (ll i : ans)
        cout << i << ' ';
    return 0;
}

/**


**/
