
import java.util.Map;
import java.util.Set;

class Solution {
    private static final Map<String, Integer> toNumber = Map.of("one",1,"two",2,"three",3,"four",4,"five",5,"six",6,"seven",7,"eight",8,"nine",9, "zero", 0);

    public int solution(String s) {
        int answer = 0;

        Set<Map.Entry<String, Integer>> entries = toNumber.entrySet();

        for (Map.Entry<String, Integer> entry : entries) {
            String key = entry.getKey();
            Integer value = entry.getValue();
            s = s.replaceAll(key, value.toString());
        }

        return Integer.parseInt(s);
    }
}