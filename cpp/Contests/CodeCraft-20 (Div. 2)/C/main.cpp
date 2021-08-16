#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll n, m, p;
vector <ll> a, b;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> p;
    a.resize(n);
    b.resize(m);
    ll ansa = -1, ansb = -1;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        if (ansa == -1 && a[i] % p) {
            ansa = i;
        }
    }
    for (ll j = 0; j < m; ++j) {
        cin >> b[j];
        if (ansb == -1 && b[j] % p) {
            ansb = j;
        }
    }
    cout << ansa + ansb << '\n';
    return 0;
}

/**


**/
