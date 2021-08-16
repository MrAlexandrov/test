#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll INF = 1e6 + 8;
ll q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> q;
    while (q--) {
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        ll ptr0 = INF, ptr1 = INF;
        for (ll i = 0; i < n; ++i)
            if (s[i] == '0') {
                ptr0 = i;
                break;
            }
        for (ll i = 0; i < n; ++i)
            if (s[i] == '1') {
                ptr1 = i;
                break;
            }
        if (ptr0 == INF || ptr1 == INF) {
            cout << s << '\n';
            continue;
        }
        ///cout << ptr0 << ' ' << ptr1 << endl;
        while (k > 0) {
            if (ptr0 < ptr1) {
                ptr0 = ptr1 + 1;
                while (s[ptr0] == '1' && ptr0 < n)
                    ++ptr0;
            }
            if (ptr0 >= n) {
                k = 0;
                continue;
            }
            while (s[ptr0] == '0' && s[ptr1] == '1' && ptr0 - ptr1 <= k && ptr0 < n) {
                swap (s[ptr0], s[ptr1]);
                k -= ptr0 - ptr1;
                ++ptr0, ++ptr1;
            }
            if (k == 0) {
                continue;
            }
            if (s[ptr0] == '1') {
                while (s[ptr0] == '1' && ptr0 < n)
                    ++ptr0;
            }
            if (s[ptr1] == '0') {
                ptr1 = ptr0 + 1;
                while (s[ptr1] == '0' && ptr1 < n)
                    ++ptr1;
            }
            if (ptr0 >= n || ptr1 >= n) {
                k = 0;
                continue;
            }
            if (ptr0 - ptr1 > k) {
                swap (s[ptr0], s[ptr0 - k]);
                k = 0;
            }
        }
        cout << s << '\n';
    }
    return 0;
}
