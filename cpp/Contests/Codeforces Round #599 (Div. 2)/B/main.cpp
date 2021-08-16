#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll k;
    cin >> k;
    while (k--) {
        ll n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        vector <ll> diff;
        for (ll i = 0; i < n; ++i)
            if (s[i] != t[i])
                diff.push_back(i);
        if (diff.size() == 0 || (diff.size() == 2 && s[diff[0]] == s[diff[1]] && t[diff[0]] == t[diff[1]]))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}

/**


**/
