class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        
        // dp[i][j] represents minimum operations to convert 
        // first i characters of word1 to first j characters of word2
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // Initialize base cases
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;  // All deletions
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;  // All insertions
        }
        
        // Fill the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    // No operation needed if characters match
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // Try all three operations and take minimum
                    int replaceOp = dp[i - 1][j - 1] + 1;
                    int deleteOp = dp[i - 1][j] + 1;
                    int insertOp = dp[i][j - 1] + 1;
                    
                    dp[i][j] = min({replaceOp, deleteOp, insertOp});
                }
            }
        }
        
        return dp[m][n];
    }
};