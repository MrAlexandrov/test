#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

struct FlowNetwork {
    struct Edge {
        int from, to;
        ll cap, flow;
        int rev;
        Edge (int _from, int _to, ll _cap, int _rev) {
            from = _from;
            to = _to;
            cap = _cap;
            flow = 0;
            rev = _rev;
        }
        Edge(){}
    };
    const int INF = (int)1e9 + 7;
    const ll LLINF = (ll)1e18 + 7;
    int n;
    vector <Edge> *g;
    int *dist;
    int *parent, *parentID;
    FlowNetwork(int _n) {
        n = _n;
        g = new vector <Edge> [n + 1];
        dist = new int[n + 1];
        parent = new int[n + 1];
        parentID = new int[n + 1];
    }
    void addEdge(int from, int to, ll cap) {
        g[from].push_back(Edge(from, to, cap, (int)g[to].size()));
        g[to].push_back(Edge(to, from, 0, (int)g[from].size() - 1));
    }
    ll bfs(int n, int s, int t, ll minVal) {
        for (int i = 1; i <= n; ++i) {
            dist[i] = INF;
        }
        dist[s] = 0;
        parent[s] = -1;
        queue <int> q;
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int i = 0; i < (int)g[v].size(); ++i) {
                if (g[v][i].cap - g[v][i].flow >= minVal && dist[g[v][i].to] > dist[v] + 1) {
                    parent[g[v][i].to] = v;
                    parentID[g[v][i].to] = i;
                    dist[g[v][i].to] = dist[v] + 1;
                    q.push(g[v][i].to);
                }
            }
        }
        if (dist[t] == INF) {
            return 0;
        }
        ll flow = LLINF;
        int v = t;
        while (v != s) {
            int vv = parent[v];
            int ve = parentID[v];
            flow = min(flow, g[vv][ve].cap - g[vv][ve].flow);
            v = vv;
        }
        v = t;
        while (v != s) {
            int vv = parent[v];
            int ve = parentID[v];
            g[vv][ve].flow += flow;
            g[v][g[vv][ve].rev].flow -= flow;
            v = vv;
        }
        return flow;
    }
    ll findFlow(int s, int t) {
        ll res = 0;
        for (int i = 60; i >= 0; --i) {
            while (true) {
                ll curFlow = bfs(n, s, t, (1LL << i));
                if (curFlow == 0) {
                    break;
                }
                res += curFlow;
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector <ll> g[n + 1];
    for (ll i = 1; i <= m; ++i) {
        int v, u;
        cin >> v >> u;
        g[v].push_back(u);
    }
    ll ans = LLONG_MAX;
    for (ll s = 1; s <= n; ++s) {
        for (ll t = s + 1; t <= n; ++t) {
            FlowNetwork fn(n);
            for (ll i = 1; i <= n; ++i) {
                for (ll j : g[i]) {
                    fn.addEdge(i, j, 1);
                    fn.addEdge(j, i, 1);
                }
            }
            ans = min(ans, fn.findFlow(s, t));
        }
    }
    cout << ans << '\n';
    return 0;
}

/**
3 3
1 2
2 3
3 1

**/
