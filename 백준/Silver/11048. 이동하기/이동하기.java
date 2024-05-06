import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {

    static int N, M;
    static int[][] dp;
    static int[][] price;
    static int[] dy = {1, 0, 1};
    static int[] dx = {0, 1, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        price = new int[N][M];
        dp = new int[N][M];
        Arrays.stream(dp).forEach(d -> Arrays.fill(d, -1));
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                price[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        System.out.println(solve(0, 0));
    }

    private static int solve(int y, int x) {
        if(y >= N || x >= M) return -987654321; // 맵 밖
        if(y == N-1 && x == M-1){ //N,M에 왔을 경우
            return price[y][x];
        }

        if(dp[y][x] != -1){
            return dp[y][x];
        }

        dp[y][x] = 0;
        for (int i = 0; i < 3; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            dp[y][x] = Math.max(dp[y][x], solve(ny, nx) + price[y][x]);
        }

        return dp[y][x];
    }


}