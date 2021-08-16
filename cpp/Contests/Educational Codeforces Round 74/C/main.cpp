#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

bool debug = false;

ll q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> q;
    while (q--) {
        ll h, n;
        cin >> h >> n;
        vector <ll> p (n);
        for (ll i = 0; i < n; ++i)
            cin >> p[i];

        ll ans = 0;
        ll now = h;

        for (ll i = 0; i < n; ++i) {
            if (p[i] > now)
                continue;

            if (2 >= now)
                break;

            if (i + 1 >= n) {
                ++ans;
                break;
            }
            else {
                ll rasn = now - p[i + 1];
                if (now == p[i]) {
                    if (rasn == 1) {
                        if (i + 2 >= n) {
                            ++ans;
                            break;
                        }
                        else {
                            if (now - p[i + 2] == 2) {
                                now = p[i + 2];
                            }
                            else {
                                ++ans;
                                now = p[i + 2] + 1;
                            }
                        }
                    }
                    else {
                        now = p[i + 1] + 1;
                    }
                }
                else {
                    assert (now == p[i] + 1);
                    if (rasn == 2) {
                        now = p[i + 1];
                    }
                    else {
                        ++ans;
                        now = p[i + 1] + 1;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

/**
1
8 6
8 7 6 5 3 2

1
9 6
9 8 5 4 3 1

1
9 8
9 8 6 5 4 3 2 1

1
9 3
9 8 7

1
9 3
9 8 6

1
9 2
9 1

1
9 1
9

1
9 2
9 8

1
2 2
2 1

1
2 1
2

1
1 1
1


**/
