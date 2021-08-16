#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll n, m;
    cin >> n >> m;
    vector <ll> l(m);
    ll length = 0;
    for (ll i = 0; i < m; ++i) {
        cin >> l[i];
        length += l[i];
    }
    if (length < n) {
        cout << "-1\n";
        return 0;
    }
    vector <ll> ans(m);
    for (ll i = 0; i < m; ++i) {
        ans[i] = n - i - l[i];
        if (ans[i] < 0) {
            cout << "-1\n";
            return 0;
        }
    }
    ll ptr = m - 1;
    ll last = 0;
    while (true) {
        if (ans[ptr] <= last) {
            break;
        } else {
            ans[ptr] = last;
            last = ans[ptr] + l[ptr];
        }
        --ptr;
    }
    for (ll i : ans) {
        cout << i + 1 << ' ';
    }
    return 0;
}

/**


**/
