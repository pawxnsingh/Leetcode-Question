class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        // initialize two pointer
        int left = 0, right = 0;
        while (left < s.size() && right< g.size()) {
            if (s[left] >= g[right]) {
                // idx0 -> 1   >= idx0 -> 1
                right++;
                left++;
            } else {
                left++;
            }
        }
        return right;
    }
};