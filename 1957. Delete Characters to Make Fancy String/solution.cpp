class Solution {
public:
    string makeFancyString(string s) {
        int i = 0, j = 0, N = s.size();
        while (i < N) {
            int start = i;
            while (i < N && s[i] == s[start]) {
                if (i - start < 2) s[j++] = s[i];
                ++i;
            }
        }
        s.resize(j);
        return s;
    }
};