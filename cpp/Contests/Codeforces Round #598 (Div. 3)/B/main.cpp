#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = 1e2 + 8;
ll q;
vector <ll> a (N);
vector <bool> b (N);

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> q;
    while (q--) {
        ll n;
        cin >> n;
        for (ll i = 0; i < n; ++i)
            cin >> a[i];
        fill (b.begin(), b.end(), false);
        for (ll i = 0; i < n; ++i) {
            for (ll j = n - 2; j >= 0; --j) {
                if (a[j] > a[j + 1] && b[j] == false) {
                    swap (a[j], a[j + 1]);
                    b[j] = true;
                }
            }
        }
        for (ll i = 0; i < n; ++i)
            cout << a[i] << ' ';
        cout << '\n';
    }
    return 0;
}
