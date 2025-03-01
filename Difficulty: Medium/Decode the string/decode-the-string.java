//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int t = Integer.parseInt(in.readLine());
        while (t-- > 0) {
            String s = in.readLine();

            Solution ob = new Solution();
            out.println(ob.decodeString(s));

            out.println("~");
        }
        out.close();
    }
}
// } Driver Code Ends



class Solution {
    static String decodeString(String s) {
        Stack<Integer> countStack = new Stack<>();
        Stack<String> stringStack = new Stack<>();
        String currentString = "";
        int k = 0;

        for (char ch : s.toCharArray()) {
            if (Character.isDigit(ch)) {
                k = k * 10 + (ch - '0');
            } else if (ch == '[') {
                countStack.push(k);
                stringStack.push(currentString);
                currentString = "";
                k = 0;
            } else if (ch == ']') {
                StringBuilder decodedString = new StringBuilder(stringStack.pop());
                int repeatTimes = countStack.pop();
                for (int i = 0; i < repeatTimes; i++) {
                    decodedString.append(currentString);
                }
                currentString = decodedString.toString();
            } else {
                currentString += ch;
            }
        }
        return currentString;
    }
}