#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve() {
    ll x0, n;
    cin >> x0 >> n;
    ll d;
    if (n % 4 == 0) {
        d = 0;
    } else if (n % 4 == 1) {
        d = - n;
    } else if (n % 4 == 2) {
        d = 1;
    } else if (n % 4 == 3) {
        d = n + 1;
    }
    if (x0 & 1) {
        d *= -1;
    }
    return x0 + d;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll T;
    cin >> T;
    while (T--) {
        cout << solve() << '\n';
    }
    return 0;
}

/**
E - O - O - E - E - O - O - E
  +1  -2  -3  +4  +5  -6  -7
    1  -1  -4   0   5  -1  -8   0


O - E - E - O - O - E - E - O
  -1  +2  +3  -4  -5  +6  +7
   -1   1   4   0  -5   1   8

**/
