import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int[][] arr;
    static int[][][] dp; // [y][x][type] y,x에 왔을 때 이번에 뭘 마셔야하는지

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        arr = new int[N + 1][N + 1];
        dp = new int[N + 1][N + 1][4];
        Arrays.stream(dp).forEach(
                d -> Arrays.stream(d).forEach(
                        arr -> Arrays.fill(arr, -1)
                )
        );
        for (int i = 1; i <= N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= N; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        System.out.println(go(1, 1, 0));


    }

    private static int go(int y, int x, int type) {
        if(y > N || x > N) return 0;
        if (y == N && x == N) {
            if (type == arr[y][x]) {
                return 1;
            }
            return 0;
        }

        if (dp[y][x][type] != -1) {
            return dp[y][x][type];
        }

        int ret = 0;
        int isDrink = type == arr[y][x] ? 1 : 0; //현재 마실 수 있는지
        int nextDrink = type == arr[y][x] ? (arr[y][x]+1) % 3 : type; //다음에 뭘 마셔야 하는지
        
        ret = Math.max(ret, go(y, x + 1, nextDrink) + isDrink);
        ret = Math.max(ret, go(y+1, x, nextDrink) + isDrink);

        return dp[y][x][type] = ret;
    }

}