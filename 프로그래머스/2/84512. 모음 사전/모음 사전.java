import java.util.ArrayList;
import java.util.List;


class Solution {
    private static final char[] CHARS = "AEIOU".toCharArray();
    
    private void generate(String word, List<String> words){
        words.add(word);
        
        if(word.length() == 5) return;
        
        for(char c : CHARS){
            generate(word+c, words);
        }
    }

    public int solution(String word) {
        List<String> result = new ArrayList<>();
        generate("", result);
        return result.indexOf(word);
    }
}