import java.util.Arrays;

class Solution {
    public int solution(int[] citations) {
        Arrays.sort(citations);

        for(int h = citations.length; h >= 1; h--){
            int count = 0;
            for(int citation : citations){
                if(citation >= h) count++;
            }
            if(count >= h) return h;
        }


        return 0;
    }
}