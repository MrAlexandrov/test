#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll X, S;
    cin >> X >> S;
    if (X > S || (X + S) & 1) {
        cout << -1 << '\n';
        return 0;
    }
    if (X == S) {
        if (X == 0) {
            cout << 0 << '\n';
        } else {
            cout << 1 << '\n' << X << '\n';
        }
        return 0;
    }
    ll M = (S - X) >> 1;
    if (X + M == (X ^ M)) {
        cout << 2 << '\n' << S - M << ' ' << M << '\n';
    } else {
        cout << 3 << '\n' << X << ' ' << M << ' ' << M << '\n';
    }
    return 0;
}

/**


**/
