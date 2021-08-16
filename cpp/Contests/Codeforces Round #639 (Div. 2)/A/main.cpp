#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll T;
    cin >> T;
    while (T--) {
        ll n, m;
        cin >> n >> m;
        if (n > m) {
            swap(n, m);
        }
        if ((n <= 2 && m <= 2) || (n == 1)) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << '\n';
    }
    return 0;
}

/**


**/
