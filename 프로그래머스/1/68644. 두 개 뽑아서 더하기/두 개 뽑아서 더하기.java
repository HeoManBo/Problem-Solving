import java.util.*;

class Solution {
  public static int[] solution(int[] numbers) {
        Set<Integer> ans = new HashSet<>();
        for(int i=0; i<numbers.length; i++){
            for(int j=i+1; j < numbers.length; j++){
                int add = numbers[i] + numbers[j];
                ans.add(add);
            }
        }

        int[] arr = ans.stream().mapToInt(i -> i).toArray();
        Arrays.sort(arr);
        
        return arr;
    }
}