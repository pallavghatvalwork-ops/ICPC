#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll NEG = -4000000000000000000LL; // -4e18

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<ll> D(N);
    for (int i = 0; i < N; ++i) cin >> D[i];

    vector<vector<int> > g(N);
    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b; --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> comp_id(N, -1);
    vector<int> stack;
    int comp_cnt = 0;

    // find connected components
    for (int i = 0; i < N; ++i) {
        if (comp_id[i] != -1) continue;
        // iterative DFS/BFS
        stack.clear();
        stack.push_back(i);
        comp_id[i] = comp_cnt;
        for (size_t p = 0; p < stack.size(); ++p) {
            int u = stack[p];
            for (size_t k = 0; k < g[u].size(); ++k) {
                int v = g[u][k];
                if (comp_id[v] == -1) {
                    comp_id[v] = comp_cnt;
                    stack.push_back(v);
                }
            }
        }
        ++comp_cnt;
    }

    // group nodes by component
    vector<vector<int> > comps(comp_cnt);
    for (int i = 0; i < N; ++i) comps[comp_id[i]].push_back(i);

    // answer vector, default -1 for forbidden components or NEG for others
    vector<ll> ans(N, NEG);
    vector<char> comp_has_forbidden(comp_cnt, 0);

    for (int c = 0; c < comp_cnt; ++c) {
        // check if component contains any D == -1
        bool has_forb = false;
        for (size_t j = 0; j < comps[c].size(); ++j) {
            int u = comps[c][j];
            if (D[u] == -1) { has_forb = true; break; }
        }
        comp_has_forbidden[c] = has_forb;
        if (has_forb) {
            // all nodes in component must be -1
            for (size_t j = 0; j < comps[c].size(); ++j) {
                ans[comps[c][j]] = NEG; // mark; will print -1 later
            }
            continue;
        }

        // otherwise run max-propagation inside this component
        // initialize ans[u] = D[u] for nodes in comp
        priority_queue<pair<ll,int> > pq;
        for (size_t j = 0; j < comps[c].size(); ++j) {
            int u = comps[c][j];
            ans[u] = D[u];
            pq.push(make_pair(ans[u], u));
        }

        while (!pq.empty()) {
            pair<ll,int> top = pq.top(); pq.pop();
            ll t = top.first;
            int u = top.second;
            if (t != ans[u]) continue;
            // relax neighbors (within same component)
            for (size_t k = 0; k < g[u].size(); ++k) {
                int v = g[u][k];
                if (comp_id[v] != c) continue; // skip outside comp (shouldn't happen)
                // all nodes in this comp have D != -1 so safe to update
                ll cand = ans[u] - 1;
                if (ans[v] < cand) {
                    ans[v] = cand;
                    pq.push(make_pair(ans[v], v));
                }
            }
        }
    }

    // Print: components with forbidden => -1, otherwise print ans[i]
    for (int i = 0; i < N; ++i) {
        if (i) cout << ' ';
        if (comp_has_forbidden[comp_id[i]]) cout << -1;
        else cout << ans[i];
    }
    cout << '\n';
    return 0;
}

