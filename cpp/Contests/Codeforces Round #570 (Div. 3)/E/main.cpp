#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;
string s;

int main()
{
    cin >> n >> k;
    cin >> s;
    ll ans = 0;
    queue <string> q;
    q.push(s);
    set <string> st;
    st.insert(s);
    while (st.size() < k && q.size()) {
        string t = q.front();
        q.pop();
        for (ll i = 0; i < t.size(); ++i) {
            string temp = t.substr(0, i) + t.substr(i + 1);
            if (!st.count(temp) && st.size() < k) {
                ans += n - temp.size();
                st.insert(temp);
                q.push(temp);
            }
        }
    }
    if (st.size() < k)
        cout << -1;
    else
        cout << ans;
    return 0;
}
