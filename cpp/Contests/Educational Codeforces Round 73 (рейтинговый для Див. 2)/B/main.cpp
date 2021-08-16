#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = 1e2 + 8;
ll n;
ll table[N][N] {};

ll horse[2][8] = {
    {-2, -2, -1, -1, 1, 1, 2, 2},
    {-1, 1, -2, 2, -2, 2, -1, 1}
};

void DFS (ll x, ll y) {
    //
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n;

    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j)
            cout << ((i + j) % 2 == 0 ? 'W' : 'B');
        cout << '\n';
    }
    return 0;
    /*
    for (ll i = 0; i < n; ++i)
        for (ll j = 0; j < n; ++j)
            table[i][j] = -1;

    queue <pll> q;
    q.push({0, 0});
    bool color = true;
    table[0][0] = color;
    while (!q.empty()) {
        pll x = q.front();
        color = !table[x.first][x.second];
        q.pop();
        for (ll i = 0; i < 8; ++i) {
            pll y;
            y.first = x.first + horse[0][i];
            y.second = x.second + horse[1][i];
            if (0 <= y.first && y.first < n && 0 <= y.second && y.second < n) {
                if (table[y.first][y.second] == -1) {
                    q.push(y);
                    table[y.first][y.second] = color;
                }
            }
        }
    }
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            cout << (table[i][j] ? 'W' : 'B');
        }
        cout << '\n';
    }
    */
    return 0;
}
