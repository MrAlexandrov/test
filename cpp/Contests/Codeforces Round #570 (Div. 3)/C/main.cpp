#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll q;

ll solve() {
    ll k, n, a, b;
    cin >> k >> n >> a >> b;
    if (k / b < n)
        return -1;
    else {
        ll t = n * b;
        k -= t;
        ll rasn = a - b;
        return min(n, (k % rasn > 0 ? k / rasn : k / rasn - 1));
    }
}

int main()
{
    cin >> q;
    while (q--)
        cout << solve() << '\n';
    return 0;
}
