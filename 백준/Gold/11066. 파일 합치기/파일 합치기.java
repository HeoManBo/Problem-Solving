import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int[] arr;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int T = Integer.parseInt(st.nextToken());
        while(T-- > 0){
            int N = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            arr = new int[N + 1];
            dp = new int[N + 1][N + 1];
            for (int i = 1; i <= N; i++) {
               arr[i] = Integer.parseInt(st.nextToken());
            }
            Arrays.stream(dp).forEach(
                    a -> Arrays.fill(a, -1)
            );

            System.out.println(solve(1, N));
        }
    }

    /**
     * ㅣ ~ r 구간 까지의 파일을 합칠때 필요한 최소한의 비용
     */
    private static int solve(int l, int r) {
        if(l == r) return 0; // 더 이상 파일 합치기 X
        if(dp[l][r] != -1) return dp[l][r];

        int sum = 0;
        int ans = Integer.MAX_VALUE;
        for (int i = l; i <= r; i++) { //모든 파일을 합치는데 필요한 비용
            sum += arr[i];
        }

        for (int k = l; k <= r - 1; k++) { //분할
            int tmp = solve(l, k) + solve(k+1, r) + sum;
            ans = Math.min(tmp, ans);
        }

        return dp[l][r] = ans;
    }

}