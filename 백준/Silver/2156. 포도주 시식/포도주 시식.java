import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N =  Integer.parseInt(br.readLine());
        List<Integer> arr = new ArrayList<>();
        int[][] dp = new int[N+1][3]; //dp[i][0] : i번쨰를 처음으로 마심, dp[i][1] 이전에 한 번 마심, dp[i][2] 이전에 두 번 연속으로 먹음
        Arrays.stream(dp).forEach(d -> Arrays.fill(d, -1));

        for(int i=0; i<N; i++) {
            int num = Integer.parseInt(br.readLine());
            arr.add(num);
        }

        System.out.println(solve(N, arr, dp, 0, 0));
    }

    private static int solve(int N, List<Integer> arr, int[][] dp, int now, int cnt) {
        if(now >= N){ //마지막에 도착한 경우
            return 0;
        }
        if(dp[now][cnt] != -1){
            return dp[now][cnt];
        }
        dp[now][cnt] = 0;

        //현재꺼 안 마시고 패스
        dp[now][cnt] = solve(N, arr, dp, now+1, 0);
        //마시면 안되는 경우 -> 이전에 이미 2번 마신 경우
        if(cnt != 2){
            dp[now][cnt] = Math.max(dp[now][cnt], solve(N, arr,dp, now+1, cnt+1) + arr.get(now));
        }

        return dp[now][cnt];
    }
}
