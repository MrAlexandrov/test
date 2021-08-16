#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll n;
    cin >> n;
    ll sum = 0;
    vector <ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    vector <ll> prime;
    for (ll i = 2; i * i <= sum; ++i) {
        if (sum % i == 0) {
            prime.push_back(i);
            while (sum % i == 0)
                sum /= i;
        }
    }
    if (sum > 1)
        prime.push_back(sum);
    ll ans = LLONG_MAX;
    for (ll i : prime) {
        ll now = 0;
        ll cnt = 0;
        for (ll j = 0; j < n; ++j) {
            cnt += a[j];
            now += min(cnt % i, i - cnt % i);
        }
        ans = min(ans, now);
    }
    cout << (ans == LLONG_MAX ? -1 : ans) << endl;
    return 0;
}

/**


**/

