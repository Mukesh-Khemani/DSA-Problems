/*
 * INTUITION:
 * The problem aims to find the maximum distance between equal characters in 
 * a given string s. We use a HashMap to keep track of the indices of 
 * characters encountered during the iteration through the string. For each 
 * character, we check whether it has been seen before. If yes, we calculate 
 * the distance between the current index and the previous occurrence of the 
 * character, updating the maximum distance if necessary. If the character is 
 * encountered for the first time, its index is stored in the HashMap.
 */

import java.util.HashMap;
import java.util.Map;

class Solution {
    public int maxLengthBetweenEqualCharacters(String s) {
        Map<Character, Integer> map = new HashMap();
        int ans = -1;
        for (int i = 0; i < s.length(); i++) {
            if (map.containsKey(s.charAt(i)))
                ans = Math.max(ans, i - map.get(s.charAt(i)) - 1);
            else
                map.put(s.charAt(i), i);
        }
        return ans;
    }
}