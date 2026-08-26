class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // suf[i] = how many characters of word2
        // still need to be matched using word1[i...n-1]
        vector<int> suf(n + 1);

        int j = m - 1;

        // Match from right to left
        for (int i = n - 1; i >= 0; i--) {
            if (j >= 0 && word1[i] == word2[j]) {
                j--;
            }

            suf[i] = j + 1;
        }

        vector<int> ans;

        j = 0;
        bool changed = false;

        // Find lexicographically smallest sequence
        for (int i = 0; i < n && j < m; i++) {

            // Normal match
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }

            // Use the one allowed change
            else if (!changed && suf[i + 1] <= j + 1) {
                ans.push_back(i);
                changed = true;
                j++;
            }
        }

        // If we could not select all m indices
        if (j != m) {
            return {};
        }

        return ans;
    }
};