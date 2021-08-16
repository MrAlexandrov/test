#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

vector <ll> a;

void del (ll x) {
    ll num = x;
    for (ll i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            a.push_back(i);
            while (x % i == 0)
                x /= i;
        }
    }
    if (x > 1)
        a.push_back(x);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll n;
    cin >> n;
    del (n);
    if (a.size() == 1) {
        cout << a[0] << '\n';
    }
    else {
        cout << 1 << '\n';
    }
    return 0;
}

/**


**/
