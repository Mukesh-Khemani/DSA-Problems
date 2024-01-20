/*
 * INTUITION:
 * The problem aims to find the sum of minimum values for all subarrays of an integer 
 * array `arr`. We use a monotonic stack approach to efficiently calculate this sum. We 
 * iterate through the array, maintaining a stack of indices representing increasing 
 * minimum values. For each element, we pop elements from the stack until a greater or 
 * equal element is encountered. During this process, we calculate the contribution of 
 * each popped element to the total sum, considering the subarrays it participates in. 
 * The result is updated modulo 1000000007.
 */

import java.util.Stack;

class Solution {
    public int sumSubarrayMins(int[] arr) {
        final int MOD = 1000000007;
        Stack<Integer> st = new Stack<>();
        long result = 0;
        for (int i = 0; i <= arr.length; i++) {
            while (!st.empty() && (i == arr.length || arr[st.peek()] >= arr[i])) {
                int mid = st.pop();
                int left = st.empty() ? -1 : st.peek();
                int right = i;
                long count = (mid - left) * (right - mid) % MOD;
                result += (count * arr[mid]) % MOD;
                result %= MOD;
            }
            st.push(i);
        }
        return (int) result;
    }
}