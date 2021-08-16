#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

ll n;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n;
    string s;
    cin >> s;
    map <char, ll> m;
    for (ll i = 0; i < n; ++i)
        m[s[i]]++;
    ll mn = min (min (m['o'], m['n']), m['e']);
    vector <ll> ans;
    for (ll i = 0; i < mn; ++i)
        ans.push_back(1);
    m['o'] -= mn;
    m['n'] -= mn;
    m['e'] -= mn;
    mn = min (min (m['z'], m['e']), min (m['r'], m['o']));
    for (ll i = 0; i < mn; ++i)
        ans.push_back(0);
    if (ans.empty())
        ans.push_back(0);
    for (ll i : ans)
        cout << i << ' ';
    return 0;
}
