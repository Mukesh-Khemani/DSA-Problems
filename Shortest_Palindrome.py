# INTUITION:
# The intuition behind this solution is to find the longest palindrome prefix
# of the given string. It does this by using the KMP (Knuth-Morris-Pratt)
# algorithm to compare the original string with its reverse. The KMP algorithm
# efficiently finds the longest proper prefix which is also a suffix, which
# in this case corresponds to the longest palindrome prefix. Once we know the
# length of this palindrome prefix, we can create the shortest palindrome by
# taking the remaining characters from the end of the string, reversing them,
# and adding them to the beginning of the original string.


class Solution:
    def shortestPalindrome(self, s: str) -> str:
        longest_palindrome_prefix_length = self.kmp(s[::-1], s)
        return s[longest_palindrome_prefix_length:][::-1] + s

    def kmp(self, reversed_string: str, original_string: str) -> int:
        combined_string = original_string + '#' + reversed_string
        lps = [0] * len(combined_string)

        current_index = 1
        prefix_length = 0

        while current_index < len(combined_string):
            if combined_string[current_index] == combined_string[prefix_length]:
                prefix_length += 1
                lps[current_index] = prefix_length
                current_index += 1
            else:
                if prefix_length > 0:
                    prefix_length = lps[prefix_length - 1]
                else:
                    lps[current_index] = 0
                    current_index += 1

        return lps[-1]
