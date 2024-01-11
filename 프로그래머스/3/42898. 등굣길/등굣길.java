import java.util.Arrays;

class Solution {
    static final int MOD = 1000000007;

    int solve(int y, int x, int[][] trap, int M, int N, int[][] dp){
        if(y == N-1 && x == M-1){ //학교에 도달한 경우
            return 1;
        }
        if(dp[x][y] != -1) return dp[x][y];
        dp[x][y] = 0;

        if(y+ 1 < N){ //오른쪽으로 이동
            if(trap[x][y+1] == 0){
                dp[x][y]= solve(y + 1, x, trap, M, N, dp);
            }
        }

        if(x + 1 < M){ //아래로 이동
            if(trap[x+1][y] == 0){
                dp[x][y] = (dp[x][y] + solve(y, x+1,trap , M, N, dp)) % MOD;
            }
        }

        return dp[x][y];
    }

    public int solution(int m, int n, int[][] puddles) {
        int answer = 0;
        int[][] dp = new int[m][n];
        int[][] trap = new int[m][n];
        for(int i=0; i< puddles.length; i++){
            int[] arr = puddles[i];
            trap[arr[0]-1][arr[1]-1] = 1;
        }
        Arrays.stream(dp).forEach(a -> Arrays.fill(a, -1));
        return solve(0,0, trap, m, n, dp);
    }
}