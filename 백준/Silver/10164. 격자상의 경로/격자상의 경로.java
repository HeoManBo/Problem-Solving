import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;

public class Main {

    static int N,M, K;
    static int[][] dp;
    static int[] kCoordinate;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        // K의 arr 배열 위치 찾기
        findKCoordinate();
        dp = new int[N + 1][M + 1];
        // (1,1)부터 시작
        dp[0][1] = 1; //기저 케이스
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; //일반적인 dp
            }
        }

        // 격자 표시가 없는 경우
        if (K == 0) {
            // 그냥 값 출력
            System.out.println(dp[N][M]);
        }else{
            // (1,1)에서 K까지 좌표의 경우의 수를 구하고 (1,1) -> (k.y, k.x)까지의 경우의 수를 구하고 두 개의 값을 곱하자.
            int beforeK = dp[kCoordinate[0]][kCoordinate[1]];
            int afterK = dp[N - kCoordinate[0] + 1][M - kCoordinate[1] + 1];
            System.out.println(beforeK * afterK);
        }




        br.close();
    }

    private static void findKCoordinate() {
        int num = 1;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if(num == K){
                    kCoordinate = new int[]{i, j};
                }
                num++;
            }
        }
    }

}
