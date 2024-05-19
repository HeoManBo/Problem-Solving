
import java.io.*;
import java.util.*;

public class Main {

    static int N, M;
    static int[] arr, selected;
    static boolean[] chk ;


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        arr = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr);

        chk = new boolean[N];
        selected = new int[M];

        go(0);

    }

    private static void go(int now) {
        if (now == M) {
            for (int i = 0; i < M; i++) {
                System.out.print(selected[i] + " ");
            }
            System.out.println();
            return;
        }

        int before = -1;
        for (int i = 0; i < N; i++) {
            if (!chk[i]) {
                if (before != arr[i]) {
                    chk[i]= true;
                    before = arr[i];
                    selected[now] = arr[i];
                    go(now + 1);
                    chk[i] = false;
                }
            }
        }
    }


}