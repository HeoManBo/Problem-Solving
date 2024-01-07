import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;



class Solution {
    private static final String[][] pre = { //연산자 우선순위가 가능한 조합
            "+-*".split(""),
            "+*-".split(""),
            "-+*".split(""),
            "-*+".split(""),
            "*+-".split(""),
            "*-+".split("") 
    };


    private long calculate(String op, long left, long right){
        return switch (op){
            case "+" ->  left + right;
            case "-" ->  left - right;
            case "*" ->  left * right;
            default -> 0;
        };
    }
    
    private long calculate(List<String> tokens, String[] precedence){
        for(String op : precedence){
            for(int i=0; i<tokens.size(); i++){
                if(tokens.get(i).equals(op)){
                    long left = Long.parseLong(tokens.get(i-1));
                    long right = Long.parseLong(tokens.get(i+1));
                    long result = calculate(op, left, right);
                    tokens.remove(i-1); // left 
                    tokens.remove(i-1); // oper
                    tokens.remove(i-1); // right
                    tokens.add(i - 1, String.valueOf(result));
                    i -= 2; // left, right 제거 
                }
            }
        }
        
        return Long.parseLong(tokens.get(0));
    }

    public long solution(String expression) {
        long answer = 0;

        //수식 분리
        StringTokenizer tokenizer = new StringTokenizer(expression, "+-*", true);
        List<String> tokens = new ArrayList<>();
        while(tokenizer.hasMoreTokens()){
            tokens.add(tokenizer.nextToken());
        }
        
        long max = Long.MIN_VALUE;
        for(String[] pre : pre){
            long value = Math.abs(calculate(new ArrayList<>(tokens), pre));
            if(value > max){
                max = value;
            }
        }
        
        return max;
    }
}