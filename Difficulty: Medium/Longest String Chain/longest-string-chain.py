#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends

#User function Template for python3

class Solution:
    def longestStringChain(self, words):
        ans = 0
        sorted_strings = sorted(words, key=len)  # Sort words by length
        dp = {}  # Dictionary to store the longest chain ending at each word
        
        for word in sorted_strings:  # Process words in increasing order of length
            dp[word] = 1  # Initialize with at least a length of 1
            for i in range(len(word)):
                predecessor = word[:i] + word[i+1:]  # Remove one character
                if predecessor in dp:
                    dp[word] = max(dp[word], dp[predecessor] + 1)  # Update chain length
            
            ans = max(ans, dp[word])  # Update maximum chain length
        
        return ans

#{ 
 # Driver Code Starts.
if __name__ == '__main__': 
    t = int(input())
    for _ in range (t):
        words = input().split()
        ob = Solution()
        res = ob.longestStringChain(words)
        print(res)
        print("~")
# } Driver Code Ends