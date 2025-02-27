//{ Driver Code Starts
import java.util.*;

class Get_Min_From_Stack {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt(); // Number of test cases

        while (T-- > 0) {
            int q = sc.nextInt(); // Number of queries
            Solution g = new Solution();

            while (q-- > 0) {
                int qt = sc.nextInt();

                if (qt == 1) {
                    int att = sc.nextInt();
                    g.push(att);
                } else if (qt == 2) {
                    g.pop(); // Just call pop(), do not print anything
                } else if (qt == 3) {
                    System.out.print(g.peek() + " "); // Print top element
                } else if (qt == 4) {
                    System.out.print(g.getMin() + " "); // Print minimum element
                }
            }
            System.out.println("\n~");
        }
        sc.close();
    }
}

// } Driver Code Ends


class Solution {
    int minEle;
    Stack<Integer> stack1 = new Stack<>();
    Stack<Integer> stack2 = new Stack<>();
    
    int peek() {
        if(stack1.isEmpty()) return -1;
        return stack1.peek();
    }
	
    int getMin() {
        if(stack2.isEmpty()) return -1;
        return stack2.peek();
    }
    
    int pop() {
        if(stack1.isEmpty()) return -1;
        int popped = stack1.pop();
        if(popped == stack2.peek())
            stack2.pop();
        return popped;
    }

    void push(int x) {
        stack1.push(x);
        if(stack2.isEmpty()) stack2.push(x);
        else if(x <= stack2.peek())
            stack2.push(x);
    }	
}