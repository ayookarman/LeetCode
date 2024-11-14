class Solution {
public:
    int minimizedMaximum(int n, vector<int>& Q) {
        long long L = 1, R = accumulate(begin(Q), end(Q), 0LL);
        auto valid = [&](int M) {
            int ans = 0;
            for (int n : Q) ans += (n + M - 1) / M; // ceil(n / M)
            return ans <= n;
        };
        while (L <= R) {
            long long M = (L + R) / 2;
            if (valid(M)) R = M - 1;
            else L = M + 1;
        }
        return L;
    }
};