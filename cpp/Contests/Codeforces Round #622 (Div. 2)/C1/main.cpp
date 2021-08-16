#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    vector <ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector <ll> ans(n, 0LL);
    ll mx = 0, ptr = 0;
    for (ll i = 0; i < n; ++i) {
        fill(ans.begin(), ans.end(), 0LL);
        ll now = 0;
        ans[i] = a[i];
        now += ans[i];
        for (ll j = i - 1; j >= 0; --j) {
            ans[j] = min(a[j], ans[j + 1]);
            now += ans[j];
        }
        for (ll j = i + 1; j < n; ++j) {
            ans[j] = min(a[j], ans[j - 1]);
            now += ans[j];
        }
        if (now > mx) {
            mx = now;
            ptr = i;
        }
    }
    fill(ans.begin(), ans.end(), 0LL);
    ll i = ptr;
    ans[i] = a[i];
    for (ll j = i - 1; j >= 0; --j) {
        ans[j] = min(a[j], ans[j + 1]);
    }
    for (ll j = i + 1; j < n; ++j) {
        ans[j] = min(a[j], ans[j - 1]);
    }
    for (ll i : ans) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}

/**


**/
