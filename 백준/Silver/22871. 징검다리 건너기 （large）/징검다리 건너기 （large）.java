import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {

    static int N;
    static int[] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        arr = new int[N+1];
        for (int i = 1; i <= N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        long l = 1, r = dist(N, 1);
        long ans = 0;
        while (l <= r) {
            long mid = (l+r)/2;
            if(valid(mid)) {
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }

        System.out.println(ans);
    }

    private static boolean valid(long K) {
        boolean[] chk = new boolean[N + 1];
        chk[1] = true;
        Deque<Integer> q = new ArrayDeque<>();
        q.push(1);

        while (!q.isEmpty()) {
            int now = q.pop();

            if(now == N) return true;

            for (int i = now + 1; i <= N; i++) {
                if (dist(i, now) <= K && !chk[i]) {
                    chk[i] = true;
                    q.push(i);
                }
            }
        }

        return false;
    }

    private static long dist(int target, int now) {
        return (long)(target - now) * ((long)1 + Math.abs(arr[target] - arr[now]));
    }
}