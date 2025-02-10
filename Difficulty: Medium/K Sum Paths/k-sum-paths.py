'''
class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None
'''
class Solution:
    def sumK(self, root, k):
        # code here
        def explorePaths(node, currentTotal, prefixSums):
            if node is None:
                return 0

            currentTotal += node.data
            pathCount = prefixSums.get(currentTotal - k, 0)

            # Update prefix sums dictionary
            prefixSums[currentTotal] = prefixSums.get(currentTotal, 0) + 1

            # Recur for left and right subtrees
            leftPaths = explorePaths(node.left, currentTotal, prefixSums)
            rightPaths = explorePaths(node.right, currentTotal, prefixSums)

            # Backtrack by removing the current sum entry
            prefixSums[currentTotal] -= 1
            if prefixSums[currentTotal] == 0:
                del prefixSums[currentTotal]

            return pathCount + leftPaths + rightPaths

        prefixSums = {0: 1}
        return explorePaths(root, 0, prefixSums)


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import sys

sys.setrecursionlimit(100000)
from collections import deque
from collections import defaultdict


class Node:

    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None


# Function to Build Tree
def buildTree(s):
    #Corner Case
    if (len(s) == 0 or s[0] == "N"):
        return None

    # Creating list of strings from input
    # string after spliting by space
    ip = list(map(str, s.split()))

    # Create the root of the tree
    root = Node(int(ip[0]))
    size = 0
    q = deque()

    # Push the root to the queue
    q.append(root)
    size = size + 1

    # Starting from the second element
    i = 1
    while (size > 0 and i < len(ip)):
        # Get and remove the front of the queue
        currNode = q[0]
        q.popleft()
        size = size - 1

        # Get the current node's value from the string
        currVal = ip[i]

        # If the left child is not null
        if (currVal != "N"):

            # Create the left child for the current node
            currNode.left = Node(int(currVal))

            # Push it to the queue
            q.append(currNode.left)
            size = size + 1
        # For the right child
        i = i + 1
        if (i >= len(ip)):
            break
        currVal = ip[i]

        # If the right child is not null
        if (currVal != "N"):

            # Create the right child for the current node
            currNode.right = Node(int(currVal))

            # Push it to the queue
            q.append(currNode.right)
            size = size + 1
        i = i + 1
    return root


if __name__ == "__main__":
    t = int(input())
    for _ in range(0, t):
        s = input()
        root = buildTree(s)
        d = int(input())
        ob = Solution()
        print(ob.sumK(root, d))

        print("~")

# } Driver Code Ends