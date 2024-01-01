/*
 * INTUITION:
 * The problem aims to maximize the contentment of children by distributing 
 * cookies. We employ a greedy approach, sorting both the arrays of children's 
 * greed levels (`g`) and available cookies sizes (`s`). By iterating through 
 * the sorted arrays, we assign cookies to children, starting with the ones 
 * with lower greed levels. If the size of a cookie is sufficient for a child's 
 * greed, both the child and cookie indices are incremented, ensuring a fair 
 * and optimal distribution. The function terminates when either all children 
 * are content or there are no more cookies to distribute, ultimately returning 
 * the count of maximally content children. 
 */

import java.util.Arrays;

class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int maxChildren = 0;
        int cookie = 0;
        while (cookie < s.length && maxChildren < g.length) {
            if (s[cookie] >= g[maxChildren])
                maxChildren++;
            cookie++;
        }
        return maxChildren;
    }
}