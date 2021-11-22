#include <bits/stdc++.h>
using namespace std;
typedef int ll;

const ll N = 16;

ll X[N][N]{};

ll depth = 20;

void DFS(ll u) {

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    for (ll i = 0; i < N; ++i) {
        for (ll j = 0; j < N; ++j) {
            X[i][j] = N;
        }
    }
    for (ll i = 0; i < N; ++i) {
        X[i][i] = 0;
    }

    for (ll i = 0; i < N; ++i) {
        ll to1 = i / 2;
        ll to2 = (i * 2) % 16;
        ll to3 = (i + 3) % 16;
        X[i][to1] = min(X[i][to1], 1);
        X[i][to2] = min(X[i][to2], 1);
        X[i][to3] = min(X[i][to3], 1);
    }

    for (ll i = 0; i < N; ++i) {
        for (ll j = 0; j < N; ++j) {
            cout << X[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}

/**
1. / 2
2. * 2
3. + 3


0 -> 3 -> 1 -> 0
       -> 6 -> 12
            -> 9
**/
