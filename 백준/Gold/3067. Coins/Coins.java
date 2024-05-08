import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {


    static int N, M;
    static int[] coin;
    static int[][] dp;

    private static int solve(int cur, int sum) {
        if(sum > M) return 0;
        if (cur >= N) {
            if(sum == M) return 1;
            return 0;
        }
        if(sum == M) return 1;

        if(dp[cur][sum] != -1) return dp[cur][sum];

        dp[cur][sum] = 0;

        //이번건 패스
        int ret = 0;
        ret += solve(cur + 1, sum);

        int s = sum;
        while (s + coin[cur] <= M) {
            s += coin[cur];
            ret += solve(cur + 1, s);
        }

        return dp[cur][sum] = ret;
    }

    private void recursive() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int T = Integer.parseInt(st.nextToken());
        for (int t = 0; t < T; t++) {
            N = Integer.parseInt(br.readLine());
            coin = new int[N];
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < N; i++) {
                coin[i] = Integer.parseInt(st.nextToken());
            }
            dp = new int[21][10_001];
            Arrays.stream(dp).forEach(d -> Arrays.fill(d, -1));
            M = Integer.parseInt(br.readLine());
            System.out.println(solve(0, 0));
        }
    }



    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int T = Integer.parseInt(st.nextToken());
        for (int t = 0; t < T; t++) {
            N = Integer.parseInt(br.readLine());
            int[] coin = new int[N];
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < N; i++) {
                coin[i] = Integer.parseInt(st.nextToken());
            }
            int[] dp = new int[10_001];
            dp[0] = 1; //0원을 만드는 방법은
            int M = Integer.parseInt(br.readLine());
            for (int i = 0; i < N; i++) {
                for (int j = coin[i]; j <= M; j++) { // coin[i]원으로 만들 수 있는 경우의 수
                    dp[j] += dp[j - coin[i]];
                }
            }

            System.out.println(dp[M]);
        }
    }

}