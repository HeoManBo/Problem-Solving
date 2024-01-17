import java.util.Stack;

class Solution {
    private int ans = 0;
    private int target;
    private int[] numbers ;
    
    public int solution(int[] numbers, int target) {
        this.numbers = numbers;
        this.target = target;
       //go(0, 0);
        
        return usingStack();
    }

    private void go(int idx, int sum) {
        if(idx == numbers.length){
            if(sum == target) ans++;
            return;
        }
        
        go(idx+1, sum - numbers[idx]);
        go(idx + 1, sum + numbers[idx]);
    }
    
    private static class Node{
         int index;
         int sum;

        public Node(int index, int sum) {
            this.index = index;
            this.sum = sum;
        }
    }
    
    private int usingStack(){
        int answer = 0;
        Stack<Node> st = new Stack<>();
        st.push(new Node(0, 0));
        while(!st.empty()){
            Node node = st.pop();
            if(node.index == numbers.length){
                if(node.sum == target) answer++;
                continue;
            }
            
            st.push(new Node(node.index+1, node.sum + numbers[node.index]));
            st.push(new Node(node.index+1, node.sum - numbers[node.index]));
        }
        
        return answer;
    }
}