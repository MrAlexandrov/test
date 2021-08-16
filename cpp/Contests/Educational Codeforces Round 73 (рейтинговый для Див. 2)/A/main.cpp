#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> q;
    while (q--) {
        ll n;
        cin >> n;
        multiset <ll> a;
        for (ll i = 0; i < n; ++i) {
            ll x;
            cin >> x;
            a.insert(x);
        }
        while (a.size() > 1 && a.find(2048) == a.end()) {
            /*
            for (auto i : a)
                cout << i << ' ';
            cout << '\n';
            */
            ll f = *a.begin();
            //cout << f << '\n';
            a.erase(a.begin());
            if (f == *a.begin()) {
                ll res = f + f;
                a.erase(a.begin());
                a.insert(res);
            }
        }
        /*
        for (auto i : a)
            cout << i << ' ';
        cout << '\n';
        */
        bool ans = false;
        for (auto i : a)
            if (i == 2048)
                ans = true;
        cout << (ans ? "YES\n" : "NO\n");
    }
    return 0;
}

/**
1
4
1024 512 64 512

**/
