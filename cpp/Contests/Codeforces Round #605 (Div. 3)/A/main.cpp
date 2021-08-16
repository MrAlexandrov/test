#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

void solve () {
    vector <ll> x(3);
    for (ll i = 0; i < 3; ++i)
        cin >> x[i];
    sort(x.begin(), x.end());
    if (x[0] == x[2]) {
        cout << 0 << endl;
        return;
    }
    if (x[0] == x[1]) {
        if (x[2] - x[1] <= 2) {
            cout << 0 << endl;
            return;
        }
        else {
            ++x[0];
            ++x[1];
            --x[2];
            cout << x[2] - x[1] + x[1] - x[0] + x[2] - x[0] << endl;
            return;
        }
    }
    if (x[1] == x[2]) {
        if (x[1] - x[0] <= 2) {
            cout << 0 << endl;
            return;
        }
        else {
            ++x[0];
            --x[1];
            --x[2];
            cout << x[2] - x[1] + x[1] - x[0] + x[2] - x[0] << endl;
            return;
        }
    }
    ++x[0];
    --x[2];
    cout << x[2] - x[1] + x[1] - x[0] + x[2] - x[0] << endl;
    return;
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
