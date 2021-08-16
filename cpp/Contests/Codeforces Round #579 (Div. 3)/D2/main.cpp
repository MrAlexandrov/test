#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    string s, t;
    cin >> s >> t;
    vector <vector <ll>> a(26);
    vector <vector <ll>> b(26);
    for (ll i = 0; i < s.size(); ++i)
        cout << s[i] - 'a' << ' ';
    cout << endl;
    for (ll i = 0; i < t.size(); ++i)
        cout << t[i] - 'a' << ' ';
    cout << endl;
    for (ll i = 0; i < 26; ++i) {
        if (a[i].size()) {
        cout << i << ": ";
        for (ll j : a[i])
            cout << j << ' ';
        cout << endl;
        }
    }   cout << endl;
    for (ll i = 0; i < 26; ++i) {
        if (b[i].size()) {
        cout << i << ": ";
        for (ll j : b[i])
            cout << j << ' ';
        cout << endl;
        }
    }   cout << endl;
    return 0;
}

/**


**/
