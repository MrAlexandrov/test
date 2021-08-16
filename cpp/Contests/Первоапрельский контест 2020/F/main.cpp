#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    set <char> yes, no;
    for (ll i = 0; i < 4; ++i) {
        string s;
        cin >> s;
        for (char j : s) {
            yes.insert(j);
        }
    }
    for (ll i = 0; i < 4; ++i) {
        string s;
        cin >> s;
        for (char j : s) {
            no.insert(j);
        }
    }
    for (char i : yes) {
        cout << i << ' ';
    }
    cout << endl;
    for (char i : no) {
        cout << i << ' ';
    }
    return 0;
}

/**


**/
