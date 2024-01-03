import java.util.ArrayList;
import java.util.List;

class Solution {
  public int[] solution(long n) {
        List<Integer> arr = new ArrayList<>();

        while(n != 0 ){
            arr.add((int)(n % 10));
            n = n/10;
        }

        int size = arr.size();
        int[] answer = arr.stream().mapToInt(Integer::intValue).toArray();
        return answer;
    }
}