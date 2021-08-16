#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

string solve() {
    ll n;
    cin >> n;
    vector <ll> a(n), b(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (ll i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector <vector <bool>> x(n, vector <bool>(2, false));
    for (ll i = 1; i < n; ++i) {
        x[i][0] = (x[i - 1][0] || (a[i - 1] == -1));
        x[i][1] = (x[i - 1][1] || (a[i - 1] == 1));
    }
    for (ll i = n - 1; i > 0; --i) {
        if (a[i] > b[i] && x[i][0]) {
            a[i] = b[i];
        }
        if (a[i] < b[i] && x[i][1]) {
            a[i] = b[i];
        }
        if (a[i] != b[i]) {
            return "NO";
        }
    }
    return (a[0] == b[0] ? "YES" : "NO");
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
    return 0;
}

/**


**/
