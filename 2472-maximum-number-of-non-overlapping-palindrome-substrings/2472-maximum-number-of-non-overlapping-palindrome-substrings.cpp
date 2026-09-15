class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        // dp[i] is the maximum number of valid palindromes
        // that can be selected from the first i characters.
        vector<int> dp(n + 1, 0);

        // Expand around every possible palindrome center.
        for (int center = 0; center < n; center++) {
            // Process odd-length palindromes.
            for (int left = center, right = center;
                 left >= 0 && right < n &&
                 s[left] == s[right];
                 left--, right++) {

                int length = right - left + 1;

                if (length >= k) {
                    // Select this palindrome after the prefix before left.
                    dp[right + 1] = max(dp[right + 1], dp[left] + 1);
                }
            }

            // Process even-length palindromes.
            for (int left = center, right = center + 1;
                 left >= 0 && right < n &&
                 s[left] == s[right];
                 left--, right++) {

                int length = right - left + 1;

                if (length >= k) {
                    // Select this palindrome after the prefix before left.
                    dp[right + 1] = max(dp[right + 1], dp[left] + 1);
                }
            }

            // Keep earlier answers available for later intervals.
            for (int i = 1; i <= n; i++) {
                dp[i] = max(dp[i], dp[i - 1]);
            }
        }

        return dp[n];
    }
};