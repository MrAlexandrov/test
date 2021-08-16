#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll n;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n;
    vector <ll> a (n);
    for (ll i = 0; i < n; ++i)
        cin >> a[i];
    ll diff = 0;
    for (ll i = 0; i < n; ++i) {
        if (a[i] % 2 == 0) {
            cout << a[i] / 2 << '\n';
        }
        else {
            if (a[i] < 0) {
                if (diff < 0) {
                    cout << a[i] / 2 << '\n';
                    ++diff;
                }
                else {
                    cout << a[i] / 2 - 1 << '\n';
                    --diff;
                }
            }
            else {
                if (diff < 0) {
                    cout << a[i] / 2 + 1 << '\n';
                    ++diff;
                }
                else {
                    cout << a[i] / 2 << '\n';
                    --diff;
                }
            }
        }
    }
    return 0;
}
