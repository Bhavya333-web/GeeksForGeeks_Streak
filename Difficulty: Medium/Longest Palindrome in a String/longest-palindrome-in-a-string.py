
class Solution:
     def longestPalindrome(self, s):
        def expand_around_center(left, right):
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            return s[left + 1:right] # Slice is exclusive of right index

        longest_palindrome = ""
        for i in range(len(s)):
            # Odd length palindrome
            palindrome1 = expand_around_center(i, i)
            if len(palindrome1) > len(longest_palindrome):
                longest_palindrome = palindrome1

            # Even length palindrome
            palindrome2 = expand_around_center(i, i + 1)
            if len(palindrome2) > len(longest_palindrome):
                longest_palindrome = palindrome2

        return longest_palindrome


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

    t = int(input())

    for _ in range(t):
        S = input()

        ob = Solution()

        ans = ob.longestPalindrome(S)

        print(ans)
        print("~")
# } Driver Code Ends