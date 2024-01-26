import java.util.ArrayList;
import java.util.List;

class Solution {
     public int solution(int n, int k) {
        int answer = 0;
        List<Integer> list = new ArrayList<>();

        while(n > 0){
            list.add(n % k);
            n /= k;
        }

        StringBuilder sb = new StringBuilder();

        for(int i = list.size() -1; i>=0; i--){
           sb.append(list.get(i));
       }

        String transtoString = sb.toString();
        String[] sp = transtoString.split("0+");

        if(sp.length != 0){
            for(String str : sp){
                long num = Long.parseLong(str);
                if(isPrime(num)){
                    answer++;
                }
            }
        }else{
            if(isPrime(Long.parseLong(transtoString))){
                answer++;
            }
        }

        return answer;
    }

    private boolean isPrime(long num) {
        if(num == 0 || num == 1) return false;
        for(long i=2; i<(long)Math.sqrt(num)+1; i++){
            if(num % i == 0) {
               return false;
            }
        }
        return true;
    }
    
}