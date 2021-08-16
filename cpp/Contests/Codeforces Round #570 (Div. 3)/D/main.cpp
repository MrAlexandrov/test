#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll q;

ll solve() {
    ll n;
    cin >> n;
    map <ll, ll/*, greater <ll>*/> m;
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        ++m[x];
    }
    /*
    for (auto i: m)
        cout << i.first << ' ' << i.second << '\n';
    cout << '\n';
    */
    vector <ll> a;
    for (auto i : m)
        a.push_back(i.second);
    sort(a.rbegin(), a.rend());
    ll ans = *a.begin();
    ll last = *a.begin();
    n = a.size();
    for (ll i = 1; i < n; ++i) {
        if (a[i] == last)
            last = a[i] - 1;
        else {
            if (a[i] >= last)
                last = last - 1;
            else
                last = a[i];
        }
        if (last > 0)
            ans += last;
    }
    return ans;
}

int main()
{
    cin >> q;
    while (q--)
        cout << solve() << '\n';

    return 0;
}

/**
1
8
1 4 8 4 5 6 3 8

1
16
2 1 3 3 4 3 4 4 1 3 2 2 2 4 1 1

**/
