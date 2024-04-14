import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static int N, M;
    static List<List<int[]>> tree = new ArrayList<>();
    static int ans = 0;


    public static void main(String[] args) throws IOException {
        input();
    }

    private static void solve(int now, int target, boolean[] chk, int sum) {
        if(now == target){
            ans = sum;
            return;
        }
        chk[now] = true;

        for(int[] x : tree.get(now)){
            int next = x[0];
            if(!chk[next]){
                solve(next, target, chk, sum + x[1]);
            }
        }

        chk[now] = false;
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        for(int i=0; i<=N; i++){
            tree.add(new ArrayList<>());
        }
        for(int i=0; i<N-1; i++){
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            tree.get(u).add(new int[]{v, cost});
            tree.get(v).add(new int[]{u, cost});
        }
        boolean[] chk = new boolean[N+1];
        for(int i=0; i<M; i++){
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            Arrays.fill(chk, false);
            solve(u, v, chk, 0);
            System.out.println(ans);
        }
        br.close();
    }
}
