#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve() {
    ll n;
    cin >> n;
    vector <ll> a;
    while (n) {
        a.push_back(n % 10);
        n /= 10;
    }
    ll res = 0;
    while (!a.empty()) {
        ll t = a.back();
        a.pop_back();
        res += t * pow(10, a.size());
        if (a.empty()) {
            return res;
        }
        a.back() += t;
        if (a.back() > 9) {
            a.back() %= 10;
            a.push_back(1LL);
        }
    }
    return res;
}

int main()
{
    ll t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}

/**


**/
