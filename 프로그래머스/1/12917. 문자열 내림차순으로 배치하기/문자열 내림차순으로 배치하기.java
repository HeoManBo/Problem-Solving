import java.util.Arrays;

class Solution {
     public String solution(String s) {
        char[] arr = s.toCharArray();
        Arrays.sort(arr);
        String ans = new String(arr);
        
        return new StringBuffer(ans).reverse().toString();
    }
}