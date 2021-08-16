#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = 1e3 + 8;
const pll ex = {-2LL, -2LL};

ll n;
pll table[N][N];
char ans[N][N];
bool used[N][N]{};
bool asdf = true;

///               D  L  U   R
vector <ll> dx = {1, 0, -1, 0};
vector <ll> dy = {0, -1, 0, 1};

bool ok(ll x, ll y) {
    return (0 <= x && x < n && 0 <= y && y < n);
}

void DFSxx(ll x, ll y, ll px = -1, ll py = -1) {
    used[x][y] = true;
    if (px == -1 && py == -1) {
        ans[x][y] = 'X';
    } else {
        ll tx = x - px;
        ll ty = y - py;
        if (tx == -1 && ty == 0) {
            ans[x][y] = 'D';
        } else if (tx == 0 && ty == -1) {
            ans[x][y] = 'R';
        } else if (tx == 0 && ty == 1) {
            ans[x][y] = 'L';
        } else if (tx == 1 && ty == 0) {
            ans[x][y] = 'U';
        }
    }
    for (ll i = 0; i < 4; ++i) {
        ll tox = x + dx[i];
        ll toy = y + dy[i];
        if (!ok(tox, toy) || used[tox][toy] || (tox == px && toy == py) || (table[x][y] != table[tox][toy])) {
            continue;
        }
        DFSxx(tox, toy, x, y);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            ans[i][j] = '.';
        }
    }
    vector <pll> xx;
    vector <pll> inf;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            ll x, y;
            cin >> x >> y;
            --x, --y;
            table[i][j] = {x, y};
            if (i == x && j == y) {
                xx.push_back({i, j});
            }
        }
    }
    for (auto i : xx) {
        DFSxx(i.first, i.second);
    }
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            if (table[i][j] == ex) {
                for (ll k = 0; k < 4; ++k) {
                    ll x = i + dx[k], y = j + dy[k];
                    if (!ok(x, y) || table[x][y] != ex) {
                        continue;
                    }
                    if (k == 0) {
                        ans[i][j] = 'D';
                    } else if (k == 1) {
                        ans[i][j] = 'L';
                    } else if (k == 2) {
                        ans[i][j] = 'U';
                    } else {
                        ans[i][j] = 'R';
                    }
                    used[i][j] = true;
                    break;
                }
            }
        }
    }
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            if (!used[i][j]) {
                cout << "INVALID\n";
                return 0;
            }
        }
    }
    cout << "VALID\n";
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
    return 0;
}

/**


**/
