class Solution {
    private int ans = 0;
    private int target;
    private int[] numbers ;
    
    public int solution(int[] numbers, int target) {
        this.numbers = numbers;
        this.target = target;
        go(0, 0);
        
        return ans;
    }

    private void go(int idx, int sum) {
        if(idx == numbers.length){
            if(sum == target) ans++;
            return;
        }
        
        go(idx+1, sum - numbers[idx]);
        go(idx + 1, sum + numbers[idx]);
    }
}