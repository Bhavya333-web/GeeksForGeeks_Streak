class Solution:
	def editDistance(self, s1, s2):
        # Code here
        def f(i, j):
            if i < 0 and j < 0:
                return 0
            if j < 0:
                return i+1
            if i < 0:
                return j+1
            if (i,j) in dp:
                return dp[(i, j)]
            if s1[i] == s2[j]:
                dp[(i, j)] = f(i-1, j-1)
            elif s1[i] != s2[j]:
                dp[(i, j)] = 1 + min(f(i-1, j), f(i, j-1), f(i-1, j-1))
            return dp[(i, j)]
                
        m, n = len(s1)-1, len(s2) - 1
        dp = {}
        return f(m, n)
#{ 
 # Driver Code Starts
if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        s1 = input()
        s2 = input()
        ob = Solution()
        ans = ob.editDistance(s1, s2)
        print(ans)
        print("~")

# } Driver Code Ends