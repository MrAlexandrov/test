#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    ll q;
    cin >> q;
    while (q--) {
        string s1, s2;
        cin >> s1 >> s2;
        vector <ll> cnt1 (26, 0LL);
        vector <ll> cnt2 (26, 0LL);
        for (char i : s1)
            ++cnt1[i - 'a'];
        for (char i : s2)
            ++cnt2[i - 'a'];
        bool ans = false;
        for (ll i = 0; i < 26; ++i)
            if (cnt1[i] && cnt2[i])
                ans = true;
        if (ans)
            cout << "YES";
        else
            cout << "NO";
        cout << '\n';
    }
    return 0;
}
