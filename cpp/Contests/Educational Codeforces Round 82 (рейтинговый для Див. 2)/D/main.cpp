#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = 60;

ll solve() {
    ll x, n;
    cin >> x >> n;
    vector <ll> a(N, 0);
    ll sum = 0;
    for (ll i = 0; i < n; ++i) {
        ll t;
        cin >> t;
        sum += t;
        t = log2(t);
        a[t]++;
    }
    if (sum < x) {
        return -1;
    }
    for (ll i = 0; i < N; ++i) {
        ll t = (1LL << i);
        if ((x & t) && a[i] > 0) {
            x -= t;
            a[i]--;
        }
    }
    ll res = 0;
    ll cnt = 0;
    for (ll i = 0; i < N; ++i) {
        ll t = (1LL << i);
        cnt >>= 1;
        cnt += a[i];
        if (x & t) {
            if (cnt > 0) {
                --cnt;
                continue;
            } else {
                for (ll j = i + 1; j < N; ++j) {
                    if (a[j] > 0) {
                        res += j - i;
                        --a[j];
                        i = j - 1;
                        break;
                    }
                }
            }
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}

/**


**/
