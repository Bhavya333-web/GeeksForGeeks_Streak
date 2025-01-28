//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            String S = br.readLine().trim();
            Solution obj = new Solution();
            ArrayList<String> ans = obj.findPermutation(S);
            Collections.sort(ans);
            for (int i = 0; i < ans.size(); i++) {
                out.print(ans.get(i) + " ");
            }
            out.println();

            out.println("~");
        }
        out.close();
    }
}

// } Driver Code Ends

class Solution 
{
 
public ArrayList<String> findPermutation(String s) {
        // Set to store unique permutations
        Set<String> uniquePermutations = new HashSet<>();

        // Function to generate permutations
        permute(s, "", uniquePermutations);

        // Convert the set to a list
        ArrayList<String> result = new ArrayList<>(uniquePermutations);
        return result;
    }

    private void permute(String s, String prefix, Set<String> uniquePermutations) {
        // If the string is empty, add the prefix to the set
        if (s.length() == 0) {
            uniquePermutations.add(prefix);
            return;
        }

        for (int i = 0; i < s.length(); i++) {
            // Choose the current character and remove it from the remaining string
            char current = s.charAt(i);
            String remaining = s.substring(0, i) + s.substring(i + 1);

            // Recurse with the updated prefix and remaining string
            permute(remaining, prefix + current, uniquePermutations);
        }
    }

}