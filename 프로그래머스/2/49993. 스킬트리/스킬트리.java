import java.util.*;

class Solution {
    
    public int solution(String skill, String[] skillTree) {
          return (int) Arrays.stream(skillTree)
                .map(s -> s.replaceAll("[^ " + skill +"]", ""))
                .filter(s -> skill.startsWith(s))
                .count();

    }
}