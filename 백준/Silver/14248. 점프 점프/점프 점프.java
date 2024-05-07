import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {


    static int N, start;
    static int[] move;


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        move = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            move[i] = Integer.parseInt(st.nextToken());
        }
        start = Integer.parseInt(br.readLine());
        boolean[] chk = new boolean[N + 1];
        int cnt = 0;
        chk[start] = true;
        Queue<Integer> q = new LinkedList<>();
        q.offer(start);
        while (!q.isEmpty()) {
            int now = q.poll();
            cnt++;

            if ((now + move[now] <= N) && !chk[now + move[now]]) {
                chk[now + move[now]] = true;
                q.add(now + move[now]);
            }

            if ((now - move[now] >= 1) && !chk[now - move[now]]) {
                chk[now - move[now]] = true;
                q.add(now - move[now]);
            }
        }

        System.out.println(cnt);
    }

}