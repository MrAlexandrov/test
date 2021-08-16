#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll INF = 1e18;
const ll N = 2e5 + 8;
pll one, two;
ll n;

ll dist (pll a, pll b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

ll dist_x (pll a, pll b) {
    return abs(a.first - b.first);
}

ll dist_y (pll a, pll b) {
    return abs(a.second - b.second);
}

ll min_x = INF, max_x = -INF, min_y = INF, max_y = -INF;
ll x, y;
ll table[N][N]{};

ll DFS (pll t, ll col = 0) {
    table[t.first][t.second] = col;
    for (ll i = -1; i <= 1; ++i) {
        for (ll j = -1; j <= 1; ++j) {
            if (abs(i) + abs(j)) {
                if (table[t.first + i][t.second + i] == -1 || (table[t.first + i][t.second + i] > -1 && table[t.first + i][t.second + i] > col + 1)) {
                    DFS({t.first + i, t.second + i}, col + 1);
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> one.first >> one.second >> two.first >> two.second;
    cin >> n;
    pair <ll, pll> graph;
    for (ll i = 0; i < n; ++i) {
        ll r, a, b;
        cin >> r >> a >> b;
        if (dist_x(one, {r, 0}) + dist_x({r, 0}, two) <= 1e5) {
            graph.push_back({r ,{a, b}});
            min_x = min(min_x, a);
            max_x = max(max_x, b);
            min_y = min(min_y, r);
            max_y = max(max_y, r);
        }
    }
    x = min_x + max_x >> 1;
    y = min_y + max_y >> 1;
    n = graph.size();
    for (ll i = 0; i < n; ++i) {
        ll yy = graph[i].first;
        ll xx1 = graph[i].second.first;
        ll xx2 = graph[i].second.second;
        for (ll j = xx1; j <= xx2; ++j)
            table[x + j][y + yy] = -1;
    }
    DFS({x + one.first, y + one.second});
    cout << table[x + two.first][y + two.second] << endl;
    return 0;
}

/**


**/
