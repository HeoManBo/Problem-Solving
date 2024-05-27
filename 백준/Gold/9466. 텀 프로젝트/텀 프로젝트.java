import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N, T, group = 0;
    static int[] arr, cnt;
    static boolean[] chk;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            N = Integer.parseInt(br.readLine());
            arr = new int[N+1];
            cnt = new int[N+1];
            chk = new boolean[N+1];
            group = 0;
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= N; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }
            for (int i = 1; i <= N; i++) {
                if (!chk[i]) {
                    dfs(i);
                }
            }

            System.out.println(N - group);
        }


    }

    private static void dfs(int now) {
        cnt[now]++;
        if (cnt[arr[now]] == 0) { //방문한 적이 없으면
            dfs(arr[now]);
        } else if (!chk[arr[now]]) { // 아직 다음 친구의 방문이 끝나지 않았으면 --> 싸이클 발생
            for (int i = arr[now]; i != now; i = arr[i]) {
                group++;
            }
            group++;
        }

        chk[now] = true;
    }


}