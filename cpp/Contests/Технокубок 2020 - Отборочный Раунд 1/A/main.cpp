#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> q;
    while (q--) {
        ll n;
        cin >> n;
        if (n == 1)
            cout << 3 << '\n';
        else if (n == 2)
            cout << 2 << '\n';
        else if (n == 3)
            cout << 1 << '\n';
        else
            cout << (n & 1) << '\n';
    }
    return 0;
}
