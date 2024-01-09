import java.util.*;

class Solution {
  public static int[] solution(int[] numbers) {
        Set<Integer> ans = new TreeSet<>();
        for(int i=0; i<numbers.length; i++){
            for(int j=i+1; j < numbers.length; j++){
                int add = numbers[i] + numbers[j];
                ans.add(add);
            }
        }
        return ans.stream().mapToInt(Integer::intValue).toArray();
    }
}