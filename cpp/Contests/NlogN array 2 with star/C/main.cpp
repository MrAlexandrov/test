#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int n;
    cin >> n;
    deque <int> a(n);
    for (int &i : a) {
        cin >> i;
    }
    int x = 0, y = 0;
    for (int i = 0; i < n; ++i) {
        if (i & 1) {
            if (a.front() > a.back()) {
                y += a.front();
                a.pop_front();
            } else {
                y += a.back();
                a.pop_back();
            }
        } else {
            if (a.front() > a.back()) {
                x += a.front();
                a.pop_front();
            } else {
                x += a.back();
                a.pop_back();
            }
        }
    }
    cout << x << ' ' << y;
    return 0;
}

/**


**/
