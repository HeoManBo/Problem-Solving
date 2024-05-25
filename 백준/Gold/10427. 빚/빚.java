import java.io.*;
import java.util.*;

public class Main {

    static int T, N;
    static long[] arr;
    static long[] sum;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        T = Integer.parseInt(st.nextToken());
        while (T-- > 0) {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            arr = new long[N+1];
            sum = new long[N+1];
            for (int i = 1; i <= N; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }

            Arrays.sort(arr);
            for (int i = 1; i <= N; i++) {
                sum[i] = arr[i] + sum[i-1];
            }

            long ans = 0;
            for (int i = 2; i <= N; i++) {
                ans += A(i);
            }
            System.out.println(ans);
        }
    }

    private static long A(int M) {
        long min = Long.MAX_VALUE;
        for (int i = M; i <= N; i++) {
            min = Math.min(min, (arr[i] * M) - sum[i] + sum[i - M]);
        }

        return min;
    }


}