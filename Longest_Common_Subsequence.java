/*
 * INTUITION:
 * The problem aims to find a solution for finding the length of the longest common 
 * subsequence (LCS) between two input strings, `text1` and `text2`. We use a 2D array 
 * `dp` to store the lengths of LCS for various subproblems. The nested loops iterate 
 * through each character of the input strings, and if the characters at the corresponding 
 * positions match, the length of the common subsequence is updated based on the diagonal 
 * element plus one. Otherwise, we take the maximum value from the adjacent elements in 
 * the dp array. The final result is stored in the bottom-right cell of the dp array, 
 * representing the length of the LCS.
 */

class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int size1 = text1.length();
        int size2 = text2.length();

        int[][] dp = new int[size1 + 1][size2 + 1];

        for (int i = 1; i <= size1; i++) {
            for (int j = 1; j <= size2; j++) {
                if (text1.charAt(i - 1) == text2.charAt(j - 1))
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[size1][size2];
    }
}