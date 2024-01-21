/*
 * INTUITION:
 * We iterate through the array of house values, maintaining two variables 
 * (`Rob` and `noRob`) that represent the maximum amount robbed with and 
 * without robbing the current house, respectively. For each house, we 
 * calculate the new maximum amounts considering the options of robbing or 
 * not robbing the current house. We update the variables accordingly and 
 * returns the maximum value between the final `Rob` and `noRob`, representing 
 * the optimal solution for maximizing the total robbed amount while 
 * avoiding adjacent house robberies.
 */

class Solution {
    public int rob(int[] nums) {
        int Rob = 0;
        int noRob = 0;
        for (int i = 0; i < nums.length; i++) {
            int newRob = noRob + nums[i];
            int newNoRob = Math.max(noRob, Rob);
            Rob = newRob;
            noRob = newNoRob;
        }
        return Math.max(Rob, noRob);
    }
}