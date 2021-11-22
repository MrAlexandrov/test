#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector <bool> x(n, false);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        x[b - 1] = true;
    }
    for (int i = 0; i < n; ++i) {
        if (!x[i]) {
            for (int j = 0; j < n; ++j) {
                if (j == i) {
                    continue;
                }
                cout << i + 1 << ' ' << j + 1 << '\n';
            }
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

/**
2
7 4
1 2 3
3 4 5
5 6 7
6 5 4
5 3
1 2 3
2 3 4
3 4 5

**/
