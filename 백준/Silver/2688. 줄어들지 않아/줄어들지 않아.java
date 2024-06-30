import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.EnumSet;

public class Main {

    static long[][] dp = new long[65][10];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        Arrays.stream(dp).forEach(d -> Arrays.fill(d, -1));
        for (int i = 0; i <= 9; i++) {
            dp[1][i] = 1;
        }
        for (int i = 2; i <= 64; i++) {
            for (int j = 0; j <= 9; j++) {
                go(i, j);
            }
        }

        StringBuilder sb = new StringBuilder();
        while (T-- > 0) {
            int N = Integer.parseInt(br.readLine());
            long sum = Arrays.stream(dp[N]).sum();
            sb.append(sum).append('\n');
        }

        System.out.println(sb);

    }

    // dp[now][num], 현재 자리수 now, 현재 숫자 num일 때 붙여넣기
    private static long go(int now, int num) {
        if(now <= 0){
            return 1;
        }

        if(dp[now][num] != -1){
            return dp[now][num];
        }

        dp[now][num] = 0;

        for (int i = 0; i <= num; i++) {
            dp[now][num] += go(now-1, i); // now-1번째 자리에 i번을 붙임
        }

        return dp[now][num];
    }


}
