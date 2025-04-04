//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();
        while (tc-- > 0) {
            int V = sc.nextInt();
            int E = sc.nextInt();
            int[][] edges = new int[E][2];
            for (int i = 0; i < E; i++) {
                edges[i][0] = sc.nextInt();
                edges[i][1] = sc.nextInt();
            }

            Solution obj = new Solution();
            boolean ans = obj.isCycle(V, edges);
            System.out.println(ans ? "true" : "false");
            System.out.println("~");
        }
        sc.close();
    }
}

// } Driver Code Ends


class Solution {
    class Node {
        int parent;
        int node;
        
        Node(int parent, int node) {
            this.parent = parent;
            this.node = node;
        }
    }
    
    public boolean isCycle(int V, int[][] edges) {
        // Create adjacency list
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }
        // Fill the adjacency list with the edges
        for (int[] edge : edges) {
            adj.get(edge[0]).add(edge[1]);
            adj.get(edge[1]).add(edge[0]);
        }
        
        // Array to track visited nodes
        boolean[] visited = new boolean[V];
        
        // Perform BFS from each node (handle disconnected components)
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (bfs(i, adj, visited)) {
                    return true;  // Cycle detected
                }
            }
        }
        
        return false;  // No cycle found
    }
    
    private boolean bfs(int start, ArrayList<ArrayList<Integer>> adj, boolean[] visited) {
        // Queue for BFS with parent and node information
        Queue<Node> queue = new LinkedList<>();
        queue.add(new Node(-1, start)); // Start node has no parent (-1)
        
        // Mark the start node as visited
        visited[start] = true;
        
        while (!queue.isEmpty()) {
            Node current = queue.poll();
            
            // Traverse all adjacent nodes
            for (int neighbor : adj.get(current.node)) {
                // If the neighbor is visited and is not the parent, a cycle is detected
                if (visited[neighbor] && neighbor != current.parent) {
                    return true;  // Cycle found
                }
                
                // If the neighbor hasn't been visited, mark it as visited and enqueue it
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.add(new Node(current.node, neighbor));
                }
            }
        }
        
        return false;  // No cycle found in this BFS traversal
    }
}
