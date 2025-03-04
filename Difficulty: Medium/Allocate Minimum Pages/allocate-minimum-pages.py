class Solution:
    def findPages(self, arr, k):
        def is_valid(arr, n, k, max_pages):
            students = 1
            current_pages = 0
            for pages in arr:
                if pages > max_pages:
                    return False 
                if current_pages + pages > max_pages:
                    students += 1 
                    current_pages = pages 
                    if students > k: 
                        return False
                else:
                    current_pages += pages
            return True
        n = len(arr)
        if k > n: 
            return -1
        low = max(arr)
        high = sum(arr)
        result = -1
        while low <= high:
            mid = (low + high) // 2
            if is_valid(arr, n, k, mid):
                result = mid  
                high = mid - 1
            else:
                low = mid + 1 
        return result
#{ 
 # Driver Code Starts
#Initial Template for Python 3
import bisect
#Main
if __name__ == '__main__':
    t = int(input())
    while t:
        t -= 1
        A = [int(x) for x in input().strip().split()]
        nd = [int(x) for x in input().strip().split()]
        D = nd[0]
        ob = Solution()
        ans = ob.findPages(A, D)
        print(ans)
        print("~")

# } Driver Code Ends