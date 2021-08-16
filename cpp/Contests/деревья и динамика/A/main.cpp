#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


const ll N = 1e6 + 8;
const ll INF = (ll)1e12;

ll n, k;
vector <ll> g[N];

struct item {
    ll can = 0;
    ll cannot = 0;
    ll higest = INF;
};

vector <item> a(N);

void DFS1 (ll v, ll dad = 0) {
    if (g[v].size() == 1 && v != 0) {
        a[v].can = 1;
        a[v].cannot = 0;
        a[v].higest = 0;
        return;
    }
    for (ll u : g[v]) {
        if (u != dad) {
            DFS1(u, v);
        }
    }
    ll locale_cannot = 0;
    ll locale_higest = INF;
    for (ll u : g[v]) {
        if (a[u].higest < k) {
            a[v].can += a[u].can;
            locale_cannot = max(locale_cannot, a[u].cannot);
        } else {
            locale_cannot = max(locale_cannot, a[u].can + a[u].cannot);
        }
        locale_higest = min(locale_higest, a[u].higest + 1);
    }
    a[v].cannot = locale_cannot;
    a[v].higest = locale_higest;
}

int main()
{
    cin >> n >> k;
    for (ll v = 1; v < n; ++v) {
        ll u;
        cin >> u;
        --u;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    DFS1(0);

    cout << a[0].can + a[0].cannot << endl;
    return 0;
}
