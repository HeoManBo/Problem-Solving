import java.util.Stack;


class Solution {
    public int[] solution(int[] numbers) {
        int[] answer = new int[numbers.length];
        Stack<Integer> st = new Stack<>();

        for(int i=numbers.length-1; i>=0; i--){
            while(!st.empty() && st.peek() <= numbers[i]){
                st.pop();
            }
            
            if(st.empty()){
                answer[i] = -1;
            }else{
                answer[i] = st.peek();
            }

            st.push(numbers[i]);
        }


        return answer;
    }
}