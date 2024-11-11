import java.io.*;
import java.lang.*;
import java.util.*;
class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String arr[] = br.readLine().split(" ");
            int a[] = new int[arr.length];

            for (int i = 0; i < arr.length; i++) {
                a[i] = Integer.parseInt(arr[i]);
            }
            Solution obj = new Solution();
            int f = 0;
            int A = obj.minIncrements(a);
            System.out.println(A);
        }
    }
}
class Solution {
    public int minIncrements(int[] arr) {
        Arrays.sort(arr);
        int c = 0;
        for(int i=1;i<arr.length;i++){
            if(arr[i-1]>=arr[i]){
                c+=(arr[i-1] - arr[i] + 1);
                arr[i] = arr[i - 1] +1;
            }
        }
        return c;
    }
}