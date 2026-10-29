
class Solution {
    struct Fenwick {
        int n;
        vector<int> bit;

        Fenwick(int n) : n(n), bit(n + 2, 0) {}

        void add(int i, int val) {
            for (++i; i <= n; i += i & -i)
                bit[i] ^= val;
        }

        void update(int l, int r, int val) {
            add(l, val);
            if (r + 1 < n)
                add(r + 1, val);
        }

        int get(int i) {
            int ans = 0;
            for (++i; i > 0; i -= i & -i)
                ans ^= bit[i];
            return ans;
        }
    };

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        const int LOG = 17;
        vector<vector<int>> up(LOG, vector<int>(n));
        vector<int> depth(n, 0), tin(n), tout(n);
        vector<int> parent(n, -1), order;

        // Iterative DFS
        stack<int> st;
        st.push(0);
        parent[0] = 0;

        while (!st.empty()) {
            int u = st.top();
            st.pop();

            tin[u] = order.size();
            order.push_back(u);
            up[0][u] = parent[u];

            for (int v : adj[u]) {
                if (v == parent[u]) continue;
                parent[v] = u;
                depth[v] = depth[u] + 1;
                st.push(v);
            }
        }

        // Calculate subtree sizes and exit indices
        vector<int> sz(n, 1);

        for (int i = n - 1; i > 0; i--) {
            int u = order[i];
            sz[parent[u]] += sz[u];
        }

        for (int u = 0; u < n; u++)
            tout[u] = tin[u] + sz[u] - 1;

        // Binary lifting table
        for (int j = 1; j < LOG; j++) {
            for (int u = 0; u < n; u++) {
                up[j][u] = up[j - 1][up[j - 1][u]];
            }
        }

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v])
                swap(u, v);

            int diff = depth[u] - depth[v];

            for (int j = 0; j < LOG; j++) {
                if (diff & (1 << j))
                    u = up[j][u];
            }

            if (u == v) return u;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][u] != up[j][v]) {
                    u = up[j][u];
                    v = up[j][v];
                }
            }

            return up[0][u];
        };

        Fenwick fw(n);

        for (int u = 0; u < n; u++) {
            int mask = 1 << (s[u] - 'a');
            fw.update(tin[u], tout[u], mask);
        }

        vector<bool> ans;

        for (string &q : queries) {
            stringstream ss(q);
            string type;
            int u, v;
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int oldMask = 1 << (s[u] - 'a');
                int newMask = 1 << (c - 'a');

                fw.update(tin[u], tout[u],
                          oldMask ^ newMask);

                s[u] = c;
            }
            else {
                ss >> v;

                int w = lca(u, v);

                int mask = fw.get(tin[u])
                         ^ fw.get(tin[v])
                         ^ (1 << (s[w] - 'a'));

                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};
