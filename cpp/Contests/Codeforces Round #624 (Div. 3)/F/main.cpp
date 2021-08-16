#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

#define NULL asdf

mt19937_64 rnd(time(0));

const ll NULL = 0;
const ll INF = (ll)1e18;

struct item {
    ll val, prior;
    ll dist;
    ll L, R;
    ll sz;
    item() {
        val = prior = 0;
        dist = 0;
        L = R = NULL;
        sz = 0;
    }
    item(ll x) {
        val = x, prior = rnd();
        dist = x;
        L = R = NULL;
        sz = 1;
    }
};

struct Treap {
    ll root;
    vector <item> tree;
    Treap() {
        tree.push_back(item());
        root = tree.size() - 1;
    }
    void norm(ll T) {
        if (T == NULL) {
            return;
        }
        ll L = tree[T].L, R = tree[T].R;
        tree[R].dist = tr
    }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);

    return 0;
}

/**


**/
