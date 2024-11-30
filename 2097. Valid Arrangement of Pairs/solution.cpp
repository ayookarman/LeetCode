class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& E) {
        int N = E.size();
        unordered_map<int, vector<int>> G;
        unordered_map<int, int> indegree, outdegree;
        G.reserve(N);
        indegree.reserve(N);
        outdegree.reserve(N);
        for (auto &e : E) {
            int u = e[0], v = e[1];
            outdegree[u]++;
            indegree[v]++;
            G[u].push_back(v);
        }
        int start = -1;
        for (auto &[u, vs] : G) {
            if (outdegree[u] - indegree[u] == 1) {
                start = u; 
                break;
            }
        }
        if (start == -1) start = G.begin()->first; 
        vector<vector<int>> ans;
        function<void(int)> euler = [&](int u) {
            auto &vs = G[u];
            while (vs.size()) {
                int v = vs.back();
                vs.pop_back();
                euler(v);
                ans.push_back({ u, v }); 
            }
        };
        euler(start);
        reverse(begin(ans), end(ans)); 
        return ans;
    }
};