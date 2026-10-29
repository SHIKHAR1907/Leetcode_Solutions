class Solution {
    using ll = long long;

    int n, LOG, timer;

    vector<vector<int>> adj, up;
    vector<int> tin, tout, depth;
    vector<int> initialPrefix;
    vector<int> bit;
    string s;

    int charMask(char c) { return 1 << (c - 'a'); }

    // Fenwick Tree: XOR updates and XOR prefix queries
    void updateBIT(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] ^= val;
        }
    }

    int queryBIT(int idx) {
        int ans = 0;
        for (; idx > 0; idx -= idx & -idx) {
            ans ^= bit[idx];
        }
        return ans;
    }

    // Apply XOR to the Euler interval [l, r]
    void rangeUpdate(int l, int r, int val) {
        updateBIT(l, val);

        if (r + 1 <= n) {
            updateBIT(r + 1, val);
        }
    }

    void dfs(int u, int parent, int prefix) {
        tin[u] = ++timer;
        initialPrefix[u] = prefix ^ charMask(s[u]);

        up[u][0] = parent;

        for (int j = 1; j < LOG; j++) {
            up[u][j] = up[up[u][j - 1]][j - 1];
        }

        for (int v : adj[u]) {
            if (v == parent)
                continue;

            depth[v] = depth[u] + 1;
            dfs(v, u, initialPrefix[u]);
        }

        tout[u] = timer;
    }

    bool isAncestor(int u, int v) {
        return tin[u] <= tin[v] && tout[v] <= tout[u];
    }

    int getLCA(int u, int v) {
        if (isAncestor(u, v))
            return u;
        if (isAncestor(v, u))
            return v;

        for (int j = LOG - 1; j >= 0; j--) {
            if (!isAncestor(up[u][j], v)) {
                u = up[u][j];
            }
        }

        return up[u][0];
    }

    int getPrefix(int u) { return initialPrefix[u] ^ queryBIT(tin[u]); }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s,
                                vector<string>& queries) {
        this->n = n;
        this->s = s;
        timer = 0;

        LOG = 1;
        while ((1 << LOG) <= n)
            LOG++;

        adj.assign(n, {});
        up.assign(n, vector<int>(LOG, 0));
        tin.assign(n, 0);
        tout.assign(n, 0);
        depth.assign(n, 0);
        initialPrefix.assign(n, 0);
        bit.assign(n + 2, 0);

        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Root the tree at node 0.
        dfs(0, 0, 0);

        vector<bool> answer;

        for (string& q : queries) {
            stringstream ss(q);
            string op;
            int u, v;
            ss >> op >> u;

            if (op == "update") {
                char c;
                ss >> c;

                int delta = charMask(s[u]) ^ charMask(c);

                // All root-to-node prefixes in u's subtree change.
                rangeUpdate(tin[u], tout[u], delta);

                s[u] = c;
            } else {
                ss >> v;

                int w = getLCA(u, v);

                int mask = getPrefix(u) ^ getPrefix(v) ^ charMask(s[w]);

                // Zero or one set bit means palindrome is possible.
                answer.push_back((mask & (mask - 1)) == 0);
            }
        }

        return answer;
    }
};
