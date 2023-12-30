/*
 * INTUITION:
 * The problem aims to determine whether it's possible to make all strings 
 * in the given array words equal by rearranging characters. We use an array 
 * `counts` to store the frequency of each character in the alphabet across all
 * `words`. We iterate through each word, updating the character counts 
 * accordingly. After counting, we check if the count of each character is 
 * divisible evenly by the total number of words. If any character's count is 
 * not divisible evenly, we return false, indicating that it's impossible to 
 * make the words equal. Otherwise, we returns true, signifying that the 
 * characters can be rearranged to achieve equality among all words.
 */

class Solution {
    public boolean makeEqual(String[] words) {
        int[] counts = new int[26];
        for (String word : words) {
            for (char c : word.toCharArray())
                counts[c - 'a']++;
        }
        int size = words.length;
        for (int val : counts) {
            if (val % size != 0)
                return false;
        }
        return true;
    }
}