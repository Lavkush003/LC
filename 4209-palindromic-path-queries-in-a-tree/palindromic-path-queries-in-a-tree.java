
import java.util.*;

class Solution {
    int n, LOG, timer;
    List<Integer>[] adj;
    int[] parent, depth, tin, tout, mask;
    int[][] up;
    int[] bit;

    public List<Boolean> palindromePath(
            int n, int[][] edges, String s, String[] queries) {

        this.n = n;
        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        adj = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }

        for (int[] e : edges) {
            adj[e[0]].add(e[1]);
            adj[e[1]].add(e[0]);
        }

        parent = new int[n];
        depth = new int[n];
        tin = new int[n];
        tout = new int[n];
        mask = new int[n];
        up = new int[LOG][n];
        bit = new int[n + 2];

        for (int i = 0; i < n; i++) {
            mask[i] = 1 << (s.charAt(i) - 'a');
        }

        buildEulerAndLCA();

        // Initialize root-to-node prefix masks.
        for (int u = 0; u < n; u++) {
            add(tin[u], mask[u]);
            add(tout[u] + 1, mask[u]);
        }

        List<Boolean> result = new ArrayList<>();

        for (String q : queries) {
            String[] p = q.split(" ");
            int u = Integer.parseInt(p[1]);

            if (p[0].equals("update")) {
                int newMask = 1 << (p[2].charAt(0) - 'a');
                int delta = mask[u] ^ newMask;

                // Update every root path passing through u.
                add(tin[u], delta);
                add(tout[u] + 1, delta);

                mask[u] = newMask;
            } else {
                int v = Integer.parseInt(p[2]);
                int lca = getLCA(u, v);

                int pathMask = prefix(tin[u])
                             ^ prefix(tin[v])
                             ^ mask[lca];

                // At most one character may have odd frequency.
                result.add((pathMask & (pathMask - 1)) == 0);
            }
        }

        return result;
    }

    void buildEulerAndLCA() {
        int[] stackNode = new int[2 * n + 5];
        boolean[] stackExit = new boolean[2 * n + 5];
        int top = 0;

        parent[0] = 0;
        for (int k = 0; k < LOG; k++) {
            up[k][0] = 0;
        }

        stackNode[top] = 0;
        stackExit[top++] = false;

        while (top > 0) {
            int node = stackNode[--top];
            boolean exiting = stackExit[top];

            if (exiting) {
                tout[node] = timer;
                continue;
            }

            tin[node] = ++timer;

            // Process exit after all children.
            stackNode[top] = node;
            stackExit[top++] = true;

            for (int nei : adj[node]) {
                if (nei == parent[node] && node != 0) {
                    continue;
                }
                if (node == 0 && nei == 0) {
                    continue;
                }

                parent[nei] = node;
                depth[nei] = depth[node] + 1;
                up[0][nei] = node;

                for (int k = 1; k < LOG; k++) {
                    up[k][nei] =
                        up[k - 1][up[k - 1][nei]];
                }

                stackNode[top] = nei;
                stackExit[top++] = false;
            }
        }
    }

    void add(int idx, int value) {
        while (idx < bit.length) {
            bit[idx] ^= value;
            idx += idx & -idx;
        }
    }

    int prefix(int idx) {
        int result = 0;
        while (idx > 0) {
            result ^= bit[idx];
            idx -= idx & -idx;
        }
        return result;
    }

    int getLCA(int u, int v) {
        if (depth[u] < depth[v]) {
            int temp = u;
            u = v;
            v = temp;
        }

        int diff = depth[u] - depth[v];

        for (int k = 0; k < LOG; k++) {
            if ((diff & (1 << k)) != 0) {
                u = up[k][u];
            }
        }

        if (u == v) return u;

        for (int k = LOG - 1; k >= 0; k--) {
            if (up[k][u] != up[k][v]) {
                u = up[k][u];
                v = up[k][v];
            }
        }

        return parent[u];
    }
}
