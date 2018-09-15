class Solution {
public:
    bool valid(int i, int j, vector<vector<int> >& g) {
        return i>=0 && i < g.size() && j >= 0 && j < g[0].size();
    }

    int fill (int i, int j, vector<vector<int> >& g, map<pair<int,int>,bool>& seen, map<pair<int,int>,int>& idx, int id) {
        if (!valid(i,j,g))
            return 0;
        if (seen[{i,j}]||(!seen[{i,j}] && g[i][j] == 0))
            return 0;

        idx[{i,j}] = id;
        seen[{i,j}] = 1;

        int r = 1;
        r += fill(i,j-1,g,seen,idx,id);
        r += fill(i-1,j,g,seen,idx,id);
        r += fill(i,j+1,g,seen,idx,id);
        r += fill(i+1,j,g,seen,idx,id);
        return r;
    }

    int solve (vector<vector<int> >& g) {

        map<pair<int,int>,bool> empty;
        map<pair<int,int>,bool> seen;
        map<pair<int,int>,int> idx;
        map<int,int> idx2sz;

        int id = 0;
        for (int i=0; i<g.size(); ++i) {
            for (int j=0; j<g[0].size(); ++j) {
                if (g[i][j] == 0) {
                    empty[{i,j}] = true;
                }
                else {
                    if (!seen[{i,j}]) {
                        id++;
                        int sz = fill (i,j,g,seen,idx,id);
                        idx2sz[id] = sz;
                    }
                }
            }
        }

        int mx = -1;
        vector<pair<int,int> > dir = {{0,-1}, {-1,0}, {0,1}, {1,0}};
        for (auto& e : empty) {
            int i = e.first.first;
            int j = e.first.second;

            int cnt = 0;
            map<int, bool> idx2seen;
            for (auto& d : dir) {
                int ni = i + d.first;
                int nj = j + d.second;
                if (valid(ni,nj,g)) {
                    int id = idx[{ni,nj}];
                    if (idx2seen.find(id) == idx2seen.end()) {
                        cnt += idx2sz[id];
                        idx2seen[id] = true;
                    }
                }
            }
            mx = max(cnt + 1, mx);
        }
        if (empty.empty())
            return g.size() * g[0].size();
        return mx;
    }
    int largestIsland(vector<vector<int>>& grid) {
        return solve(grid);
    }
};
