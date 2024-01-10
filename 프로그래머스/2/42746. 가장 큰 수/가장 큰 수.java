
import java.util.Arrays;
import java.util.stream.Collectors;

class Solution {
    public String solution(int[] numbers) {
        return Arrays.stream(numbers)
                .mapToObj(String::valueOf)
                .sorted((v1, v2) -> {
                  int original = Integer.parseInt(v1 + v2);
                  int reverse = Integer.parseInt(v2 + v1);
                  return reverse- original;
                }).collect(Collectors.joining(""))
                .replaceAll("^0+", "0");
    }
}