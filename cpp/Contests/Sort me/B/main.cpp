#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll n, m;
    cin >> n >> m;
    vector <ll> b(m);
    for (ll i = 0; i < m; ++i) {
        cin >> b[i];
    }
    sort(b.rbegin(), b.rend());

    priority_queue <ll, vector <ll>, greater <ll>> a;

    for (ll i = 0; i < n; ++i) {
        a.push(0);
    }

    for (ll i = 0; i < m; ++i) {
        ll x = a.top();
        a.pop();
        x += b[i];
        a.push(x);
    }
    for (ll i = 0; i < n - 1; ++i) {
        a.pop();
    }
    cout << a.top() << endl;
    return 0;
}

/**


**/
