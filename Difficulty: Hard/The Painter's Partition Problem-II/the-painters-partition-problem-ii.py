

class Solution:
   def minTime (self, arr, k):
        l,r=0,sum(arr)
        
        def helper(m):
            count=1
            cur=0
            for i in arr:
                if cur+i<=m:
                    cur+=i
                else:
                    count+=1
                    if count>k or i>m:
                        return 0
                    cur=i
            return 1    
        
        while l<=r:
            m=l+(r-l)//2
            if helper(m):
                ans=m
                r=m-1
            else:
                l=m+1
        return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().strip().split()))
        k = int(input())

        ob = Solution()
        print(ob.minTime(arr, k))

# } Driver Code Ends