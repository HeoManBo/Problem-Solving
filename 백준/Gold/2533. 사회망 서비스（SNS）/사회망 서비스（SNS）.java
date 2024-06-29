import java.io.*;
import java.util.*;

public class Main {

    static int N;
    static List<List<Integer>> g = new ArrayList<>();
    static boolean[] chk = new boolean[1_000_001];
    static int[][] dp = new int[1_000_001][2];

    static void go(int now){
        chk[now] = true;
        dp[now][0] = 0;
        dp[now][1] = 1; //현재 마을에 얼리어답터

        for (int next : g.get(now)) {
            if (!chk[next]) {
                go(next);
                dp[now][0] += dp[next][1];
                dp[now][1] += Math.min(dp[next][0], dp[next][1]);
            }
        }


    }

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        for (int i = 0; i <= N; i++) {
            g.add(new ArrayList<>());
        }
        for (int i = 0; i < N - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            g.get(s).add(e);
            g.get(e).add(s);
        }

        go(1);
        int ans = Math.min(dp[1][1], dp[1][0]);
        System.out.println(ans);
    }
}
