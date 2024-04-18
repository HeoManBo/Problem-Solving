import javax.swing.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static int N, M, X;
    static boolean[] chk;
    static List<List<Integer>> adj = new ArrayList<>();
    static List<List<Integer>> rev = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        X = Integer.parseInt(st.nextToken());
        for (int i = 0; i <= N; i++) {
            adj.add(new ArrayList<>());
            rev.add(new ArrayList<>());
        }
        chk = new boolean[N + 1];
        for(int i=0; i<M; i++){
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            adj.get(v).add(u);
            rev.get(u).add(v);
        }

        int[] cnt = new int[]{0,0};
        
        //확실히 나보다 앞에 있거나, 뒤에 있는 사람의 수룰 구한다.
        go(X, adj, 0, cnt);
        Arrays.fill(chk, false);
        go(X, rev, 1, cnt);

        int front = cnt[0];
        int back = cnt[1];

        System.out.println((front) + " " + (N - back + 1));
    }

    private static void go(int now, List<List<Integer>> adj, int idx, int[] cnt) {
        chk[now] = true;
        cnt[idx]++;

        for (int next : adj.get(now)) {
            if (!chk[next]) {
                go(next, adj, idx, cnt);
            }
        }
    }

}
