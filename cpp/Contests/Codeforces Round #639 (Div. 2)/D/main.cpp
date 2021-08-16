#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll N = 1e3 + 8;
const ll INF = 1e9;

ll n, m;
vector <vector <bool>> a(N, vector <bool>(N, false));
vector <vector <bool>> used(N, vector <bool>(N, false));

void bad() {
    cout << "-1\n";
    exit(0);
}

bool rr = false, cc = false;

void row() {
    for (ll i = 1; i <= n; ++i) {
        ll cnt = 0;
        for (ll j = 1; j <= m; ++j) {
            if (a[i][j - 1] == false && a[i][j] == true) {
                ++cnt;
            }
        }
        if (cnt > 1) {
            bad();
        }
        if (cnt == 0) {
            rr = true;
        }
    }
}

void col() {
    for (ll j = 1; j <= m; ++j) {
        ll cnt = 0;
        for (ll i = 1; i <= n; ++i) {
            if (a[i - 1][j] == false && a[i][j] == true) {
                ++cnt;
            }
        }
        if (cnt > 1) {
            bad();
        }
        if (cnt == 0) {
            cc = true;
        }
    }
}

bool ok(ll x, ll y) {
    return (1 <= x && x <= n && 1 <= y && y <= m);
}

vector <ll> dx = {-1, 0, 1, 0};
vector <ll> dy = {0, -1, 0, 1};

void DFS(ll x, ll y) {
    used[x][y] = true;
    for (ll i = 0; i < 4; ++i) {
        ll tox = x + dx[i];
        ll toy = y + dy[i];
        if (ok(tox, toy) && a[tox][toy] && !used[tox][toy]) {
            DFS(tox, toy);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> n >> m;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= m; ++j) {
            char x;
            cin >> x;
            a[i][j] = (x == '#');
        }
    }
    row();
    col();
    if (rr ^ cc) {
        bad();
    }
    ll ans = 0;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= m; ++j) {
            if (a[i][j] && !used[i][j]) {
                ++ans;
                DFS(i, j);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}

/**


**/

