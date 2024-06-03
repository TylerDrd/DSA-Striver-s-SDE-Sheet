class Solution {
public:
    int par(vector<int> &p, int u) {
        if(u==p[u]) return u;
        return p[u]=par(p,p[u]);
    }

    void sizejoin(vector<int> &s, int u, int v, vector<int> &p) {
        int pu = par(p, u);
        int pv = par(p, v);
        if(pu==pv) return ;
        if (s[pu] < s[pv]) {
            p[pu] = pv;
            s[pv] += s[pu];
        } else {
            p[pv] = pu;
            s[pu] += s[pv];
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> p(n * n), s(n * n, 1);
        for (int i = 0; i < p.size(); i++) p[i] = i;

        vector<int> r = {-1, 0, 1, 0};
        vector<int> c = {0, -1, 0, 1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                for (int k = 0; k < 4; k++) {
                    int nr = i + r[k];
                    int nc = j + c[k];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                        if (grid[nr][nc] == 1) {
                            int nn = i * n + j;
                            int adjnn = nr * n + nc;
                            sizejoin(s, nn, adjnn, p);
                        }
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) continue;
                set<int> comp;
                for (int k = 0; k < 4; k++) {
                    int nr = i + r[k];
                    int nc = j + c[k];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                        if (grid[nr][nc] == 1) {
                            comp.insert(par(p, nr * n + nc));
                        }
                    }
                }
                int size = 1;  // converting this cell to 1
                for (auto it : comp) {
                    size += s[it];
                }
                ans = max(size, ans);
            }
        }

        for (int i = 0; i < n * n; i++) {
            ans = max(ans, s[par(p, i)]);
        }

        return ans;
    }
};
